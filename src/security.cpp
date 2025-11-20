#include "security.h"
#include "banking.h"
#include "file_operations.h"
#include "utils.h"
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

string hash_pin(const string& pin) {
    hash<string> hasher;
    return to_string(hasher(pin));
}

bool is_strong_pin(const string& pin) {
    if (pin.length() != 4) return false;
    if (all_of(pin.begin(), pin.end(), [&pin](char c) { return c == pin[0]; })) return false;
    return true;
}

bool validate_account(const string& acc_number, const string& pin) {
    auto it = accounts.find(acc_number);
    if (it == accounts.end()) {
        log_audit_event("Failed login attempt - account not found: " + acc_number);
        cout << "Account not found.\n";
        return false;
    }
    
    Account& acc = it->second;
    check_inactivity(acc);
    
    if (acc.status == "LOCKED") {
        log_audit_event("Attempt to access locked account: " + acc_number);
        cout << "Account locked due to too many failed attempts or inactivity. Please contact customer support.\n";
        return false;
    }
    
    string hashed_pin = hash_pin(pin);
    if (acc.pin_hash == hashed_pin) {
        acc.failed_attempts = 0;
        log_audit_event("Successful login: " + acc_number);
        return true;
    } else {
        acc.failed_attempts++;
        log_audit_event("Failed login attempt for account: " + acc_number + " (attempt " + to_string(acc.failed_attempts) + ")");
        
        if (acc.failed_attempts >= MAX_FAILED_ATTEMPTS) {
            acc.status = "LOCKED";
            save_all_accounts_to_file();
            log_audit_event("Account locked: " + acc_number);
            cout << "Account locked due to too many failed attempts. Please contact customer support.\n";
        } else {
            cout << "Invalid PIN. " << (MAX_FAILED_ATTEMPTS - acc.failed_attempts) << " attempts remaining.\n";
            save_all_accounts_to_file();
        }
        return false;
    }
}