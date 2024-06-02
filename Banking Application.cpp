#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accNum, string accHolderName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = accHolderName;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolderName() {
        return accountHolderName;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }

    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;
    int nextAccountNumber;

public:
    Bank() {
        nextAccountNumber = 1;
    }

    void createAccount(string accHolderName, double initialBalance) {
        Account newAccount(nextAccountNumber, accHolderName, initialBalance);
        accounts.push_back(newAccount);
        cout << "Account created successfully! Your account number is " << nextAccountNumber << endl;
        nextAccountNumber++;
    }

    void viewAccount(int accNum) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                account.displayAccountDetails();
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void depositMoney(int accNum, double amount) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                account.deposit(amount);
                cout << "Deposit successful! New balance is " << account.getBalance() << endl;
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void withdrawMoney(int accNum, double amount) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                if (account.withdraw(amount)) {
                    cout << "Withdrawal successful! New balance is " << account.getBalance() << endl;
                } else {
                    cout << "Insufficient balance!" << endl;
                }
                return;
            }
        }
        cout << "Account not found!" << endl;
    }
};

int main() {
    Bank bank;
    int choice, accNum;
    string name;
    double amount;

    while (true) {
        cout << "1. Create Account" << endl;
        cout << "2. View Account" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> amount;
                bank.createAccount(name, amount);
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> accNum;
                bank.viewAccount(accNum);
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.depositMoney(accNum, amount);
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdrawMoney(accNum, amount);
                break;

            case 5:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
