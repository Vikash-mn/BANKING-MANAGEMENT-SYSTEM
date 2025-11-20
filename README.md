# Banking System

A comprehensive console-based banking system written in C++ that simulates real-world banking operations with robust security features and data persistence.

## Features

### Core Banking Operations
- **Account Creation**: Create new savings or current accounts with comprehensive customer details
- **Deposit & Withdrawal**: Secure money transactions with daily limits and validation
- **Fund Transfers**: Transfer money between accounts with transaction safety
- **Transaction History**: View detailed transaction logs for any account
- **PIN Management**: Change PIN with strong validation requirements
- **Account Statements**: Generate detailed account statements with balance calculations

### Advanced Features
- **Interest Calculation**: Calculate and apply interest on accounts
- **Bill Payments**: Pay utility bills and other services
- **Account Closure**: Close accounts with balance verification

### Security Features
- **PIN Authentication**: 4-digit PIN with strength validation
- **Account Locking**: Automatic locking after failed attempts or inactivity
- **Audit Logging**: Comprehensive logging of all operations
- **Transaction Safety**: Rollback mechanisms for failed transactions
- **Input Validation**: Robust validation for all user inputs

## Prerequisites

### Windows
- MinGW-w64 GCC (g++) compiler
- Windows Command Prompt or PowerShell

### Linux/macOS
- GCC compiler (g++)
- GNU Make

## Project Structure

```
BankingSystem/
├── src/
│   ├── main.cpp           # Application entry point
│   ├── banking.cpp        # Core banking operations
│   ├── banking.h          # Banking function declarations
│   ├── utils.cpp          # Utility functions
│   ├── utils.h            # Utility function declarations
│   ├── security.cpp       # Security and authentication
│   ├── security.h         # Security function declarations
│   ├── file_operations.cpp # File I/O operations
│   ├── file_operations.h   # File operation declarations
├── data/
│   ├── accounts.csv       # Account data storage
│   ├── transactions.csv   # Transaction records
│   └── audit.log          # Security audit log
├── tests/
│   └── test_banking.cpp   # Unit tests
├── docs/
│   └── README.md          # This file
├── CMakeLists.txt         # CMake build configuration
├── Makefile               # GNU Make build configuration
├── run.bat                # Windows build and run script
└── run.sh                 # Linux/macOS build and run script
```

## Building and Running

### Windows (Recommended)

1. **Using the provided script**:
   ```cmd
   cd BankingSystem
   run.bat
   ```

2. **Manual compilation**:
   ```cmd
   cd BankingSystem
   g++ -std=c++11 -Wall -Wextra -O2 -I./src src/main.cpp src/banking.cpp src/utils.cpp src/security.cpp src/file_operations.cpp -o banking_system.exe
   banking_system.exe
   ```

### Linux/macOS

1. **Using Make**:
   ```bash
   cd BankingSystem
   make
   ./banking_system
   ```

2. **Using CMake**:
   ```bash
   cd BankingSystem
   mkdir build && cd build
   cmake ..
   make
   ./banking_system
   ```

3. **Manual compilation**:
   ```bash
   cd BankingSystem
   g++ -std=c++11 -Wall -Wextra -O2 -I./src src/main.cpp src/banking.cpp src/utils.cpp src/security.cpp src/file_operations.cpp -o banking_system
   ./banking_system
   ```

## Usage

The application presents a menu-driven interface with the following options:

1. **Create New Account** - Register a new customer account
2. **Deposit Money** - Add funds to an account
3. **Withdraw Money** - Remove funds from an account
4. **Transfer Money** - Move money between accounts
5. **View Account Details** - Display account information
6. **View Transaction History** - Show transaction records
7. **Change PIN** - Update account PIN
8. **Close Account** - Deactivate an account
9. **Generate Account Statement** - Create financial statement
10. **Calculate Interest** - Apply interest to account
11. **Pay Bills** - Make bill payments
12. **Exit** - Close the application

### Account Creation Process
- Enter personal details (name, gender, phone, age, email, address)
- Select account type (Savings/Current)
- Create a 4-digit PIN (must not be all same digits)
- System generates account number, CIF, IFSC, MICR codes

### Security Features
- Accounts lock after 3 failed login attempts
- Accounts lock after 180 days of inactivity
- All operations are logged to audit.log
- PINs are hashed for security

## Data Files

### accounts.csv
Stores account information in CSV format:
```
AccountNumber,Name,PINHash,Gender,Phone,Age,AccountType,Email,Address,CIF,IFSC,MICR,BranchName,BranchAddress,Balance,Status,OpeningDate,FailedAttempts,LastTransactionDate,DailyWithdrawalTotal
```

### transactions.csv
Records all transactions:
```
AccountNumber,Type,FromAccount,ToAccount,Amount,Timestamp,Description
```

### audit.log
Security and operation logs:
```
[Timestamp] Event description
```

## Code Architecture

### Core Classes and Structures

#### Account Structure
```cpp
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
```

#### Transaction Structure
```cpp
struct Transaction {
    std::string account_number;
    std::string type;
    std::string from_account;
    std::string to_account;
    double amount;
    std::string timestamp;
    std::string description;
};
```

### Key Functions

#### Banking Operations (banking.cpp)
- `create_account()` - Account creation workflow
- `deposit()` - Money deposit with validation
- `withdraw()` - Money withdrawal with limits
- `transfer_money()` - Inter-account transfers
- `view_account_details()` - Account information display
- `view_transaction_history()` - Transaction log display
- `change_pin()` - PIN update with validation
- `close_account()` - Account deactivation

#### Security Functions (security.cpp)
- `hash_pin()` - PIN hashing using std::hash
- `is_strong_pin()` - PIN strength validation
- `validate_account()` - Account authentication

#### Utility Functions (utils.cpp)
- `generate_account_number()` - Unique account number generation
- `get_current_datetime()` - Timestamp generation
- `validate_email()` - Email format validation
- `check_inactivity()` - Account inactivity monitoring
- `record_transaction()` - Transaction logging

#### File Operations (file_operations.cpp)
- `load_accounts_from_file()` - Account data loading
- `save_all_accounts_to_file()` - Account data persistence
- `save_transaction_to_file()` - Transaction recording
- `log_audit_event()` - Audit logging

### Transaction Safety
The system implements a `TransactionGuard` class that provides rollback functionality for failed operations, ensuring data consistency.

## Constants and Limits

- **Minimum Deposit**: ₹500
- **Maximum Deposit**: ₹100,000
- **Minimum Withdrawal**: ₹500
- **Daily Withdrawal Limit**: ₹50,000
- **Maximum Failed Attempts**: 3
- **Inactivity Lock Period**: 180 days

## Testing

Unit tests are available in `tests/test_banking.cpp`. To run tests:

```bash
cd BankingSystem
g++ -std=c++11 -I./src tests/test_banking.cpp src/banking.cpp src/utils.cpp src/security.cpp src/file_operations.cpp -o test_banking
./test_banking
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Ensure all tests pass
6. Submit a pull request

## License

This project is not  open source and available under the MIT License.

## Support

For issues or questions, please create an issue in the repository or contact the development team.
