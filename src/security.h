#ifndef SECURITY_H
#define SECURITY_H

#include <string>

// Security functions
std::string hash_pin(const std::string& pin);
bool is_strong_pin(const std::string& pin);
bool validate_account(const std::string& acc_number, const std::string& pin);

#endif