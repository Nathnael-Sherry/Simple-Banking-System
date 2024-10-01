#include <iostream>

using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        cout << "You have deposited Kshs" << amount << ". New balance: Kshs" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "You have withdrawn Kshs" << amount << ". New balance: Kshs" << balance << endl;
        }
    }

    void displayBalance() const {
        cout << "Your current balance is: Kshs" << balance << endl;
    }
};

void displayMenu() {
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Check balance" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    BankAccount account(500);
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double depositAmount;
                cout << "Enter deposit amount: ";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            }
            case 2: {
                double withdrawAmount;
                cout << "Enter withdraw amount: ";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            }
            case 3:
                account.displayBalance();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
