#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
    private:
        string accountNumber;
        double balance;

    protected:
        vector<string> transactionHistory;

    public:
        BankAccount(string accNum, double initialBalance)
            : accountNumber(accNum), balance(initialBalance) {
            transactionHistory.push_back("Account created with balance: " + to_string(balance));
        }

        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                transactionHistory.push_back("Deposited: " + to_string(amount));
            }
        }

        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                transactionHistory.push_back("Withdrew: " + to_string(amount));
            } else {
                transactionHistory.push_back("Failed withdrawal attempt: " + to_string(amount));
            }
        }

        double getBalance() const {
            return balance;
        }

        void showTransactions() const {
            cout << "\nTransaction History for account: " << accountNumber << endl;
            for (const string& t : transactionHistory) {
                cout << " - " << t << endl;
            }
        }
};

class SavingsAccount : public BankAccount {
    private:
        double interestRate;

    public:
        SavingsAccount(string accNum, double initialBalance, double rate)
            : BankAccount(accNum, initialBalance), interestRate(rate) {
            transactionHistory.push_back("SavingsAccount created with interest rate: " + to_string(rate));
        }

        void applyInterest() {
            double currentBalance = getBalance();
            double interest = currentBalance * interestRate;
            deposit(interest);

            transactionHistory.push_back("Interest applied: " + to_string(interest));
        }
};

int main() {
    SavingsAccount myAccount("UZ12345", 1000.0, 0.05);
    myAccount.deposit(500);
    myAccount.withdraw(200);
    myAccount.applyInterest();
    myAccount.showTransactions();
    cout << "\nFinal Balance: " << myAccount.getBalance() << endl;
    return 0;
}
