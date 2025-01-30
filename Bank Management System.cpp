#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Class to represent a bank account
class BankAccount {
public:
    string accountHolder;
    string accountNumber;
    double balance;
    vector<string> transactionHistory;

    // Constructor
    BankAccount(string holder, string accountNum, double initialDeposit = 0.0)
        : accountHolder(holder), accountNumber(accountNum), balance(initialDeposit) {
        addTransaction("Account created with initial balance: $" + to_string(initialDeposit));
    }

    // Deposit money into the account
    void deposit(double amount) {
        balance += amount;
        addTransaction("Deposited: $" + to_string(amount));
    }

    // Withdraw money from the account
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!\n";
            return false;
        }
        balance -= amount;
        addTransaction("Withdrew: $" + to_string(amount));
        return true;
    }

    // View the account balance
    void viewBalance() {
        cout << "Account Balance: $" << balance << endl;
    }

    // View transaction history
    void viewTransactionHistory() {
        if (transactionHistory.empty()) {
            cout << "No transactions available.\n";
        } else {
            cout << "Transaction History:\n";
            for (const string& transaction : transactionHistory) {
                cout << transaction << endl;
            }
        }
    }

private:
    // Helper function to record a transaction
    void addTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }
};

// Class to manage the bank
class Bank {
private:
    vector<BankAccount> accounts;

public:
    // Create a new bank account
    void createAccount() {
        string name, accountNum;
        double initialDeposit;

        cout << "Enter account holder name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter account number: ";
        getline(cin, accountNum);

        cout << "Enter initial deposit amount: $";
        cin >> initialDeposit;

        BankAccount newAccount(name, accountNum, initialDeposit);
        accounts.push_back(newAccount);

        cout << "Account created successfully!\n";
    }

    // Find an account by account number
    BankAccount* findAccount(const string& accountNum) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNum) {
                return &account;
            }
        }
        return nullptr;
    }

    // Deposit money to an account
    void depositMoney() {
        string accountNum;
        double amount;

        cout << "Enter account number: ";
        cin >> accountNum;

        BankAccount* account = findAccount(accountNum);
        if (account) {
            cout << "Enter amount to deposit: $";
            cin >> amount;
            account->deposit(amount);
            cout << "Deposit successful.\n";
        } else {
            cout << "Account not found.\n";
        }
    }

    // Withdraw money from an account
    void withdrawMoney() {
        string accountNum;
        double amount;

        cout << "Enter account number: ";
        cin >> accountNum;

        BankAccount* account = findAccount(accountNum);
        if (account) {
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            if (account->withdraw(amount)) {
                cout << "Withdrawal successful.\n";
            }
        } else {
            cout << "Account not found.\n";
        }
    }

    // View account balance
    void viewBalance() {
        string accountNum;

        cout << "Enter account number: ";
        cin >> accountNum;

        BankAccount* account = findAccount(accountNum);
        if (account) {
            account->viewBalance();
        } else {
            cout << "Account not found.\n";
        }
    }

    // View account transaction history
    void viewTransactionHistory() {
        string accountNum;

        cout << "Enter account number: ";
        cin >> accountNum;

        BankAccount* account = findAccount(accountNum);
        if (account) {
            account->viewTransactionHistory();
        } else {
            cout << "Account not found.\n";
        }
    }

    // Display the menu
    void displayMenu() {
        cout << "\nBank Management System\n";
        cout << "1. Create a new account\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. View balance\n";
        cout << "5. View transaction history\n";
        cout << "6. Exit\n";
    }
};

// Main program
int main() {
    Bank bank;
    int choice;

    while (true) {
        bank.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.depositMoney();
                break;
            case 3:
                bank.withdrawMoney();
                break;
            case 4:
                bank.viewBalance();
                break;
            case 5:
                bank.viewTransactionHistory();
                break;
            case 6:
                cout << "Exiting Bank Management System.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

