#ifndef BANKING_H
#define BANKING_H

#include <string>
#include <vector>
#include <map>
#include <functional>

// Constants
const std::string DATA_DIR = "data";
const std::string ACCOUNTS_FILE = "data/accounts.csv";
const std::string TRANSACTIONS_FILE = "data/transactions.csv";
const std::string AUDIT_LOG_FILE = "data/audit.log";
const double MIN_DEPOSIT = 500.0;
const double MAX_DEPOSIT = 100000.0;
const double MIN_WITHDRAWAL = 500.0;
const double DAILY_WITHDRAWAL_LIMIT = 50000.0;
const int MAX_FAILED_ATTEMPTS = 3;
const int INACTIVITY_LOCK_DAYS = 180;

// Account structure
struct Account {
    std::string account_number;
    std::string name;
    std::string pin_hash;
    std::string gender;
    std::string phone_number;
    int age;
    std::string account_type;
    std::string email;
    std::string address;
    std::string cif_number;
    std::string ifsc_code;
    std::string micr_code;
    std::string branch_name;
    std::string branch_address;
    double balance;
    std::string status;
    std::string opening_date;
    int failed_attempts;
    std::string last_transaction_date;
    double daily_withdrawal_total;
};

// Transaction structure
struct Transaction {
    std::string account_number;
    std::string type;
    std::string from_account;
    std::string to_account;
    double amount;
    std::string timestamp;
    std::string description;
};

// External declarations
extern std::map<std::string, Account> accounts;
extern std::vector<Transaction> transactions;

// Function declarations
void initialize_system();
void display_main_menu();
void create_account();
void deposit();
void withdraw();
void transfer_money();
void view_account_details();
void view_transaction_history();
void change_pin();
void close_account();
void generate_account_statement();
void calculate_interest();
void pay_bills();

#endif