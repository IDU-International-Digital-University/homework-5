#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class PaymentMethod {
    public:
        virtual ~PaymentMethod() = default;

        virtual bool validatePayment() = 0;
        virtual void processPayment(double amount) = 0;

        virtual double getTransactionFee(double amount) {
            return amount * 0.01;
        }
};


class CreditCard : public PaymentMethod {
    private:
        string cardNumber;
        string expiry;
        string cvv;

    public:
        CreditCard(string n, string e, string c)
            : cardNumber(n), expiry(e), cvv(c) {}

        bool validatePayment() override {
            cout << "Validating Credit Card..." << endl;
            return cardNumber.size() == 16 && cvv.size() == 3;
        }

        double getTransactionFee(double amount) override {
            return amount * 0.015;
        }

        void processPayment(double amount) override {
            if (!validatePayment()) {
                cout << "Credit card validation failed.\n";
                return;
            }
            double fee = getTransactionFee(amount);
            cout << "CreditCard Payment: " << amount
                << " | Fee: " << fee << endl;
        }
};

class DebitCard : public PaymentMethod {
    private:
        string cardNumber;
        string pin;

    public:
        DebitCard(string n, string p) : cardNumber(n), pin(p) {}

        bool validatePayment() override {
            cout << "Validating Debit Card..." << endl;
            return cardNumber.size() == 16 && pin.size() == 4;
        }

        double getTransactionFee(double amount) override {
            return amount * 0.005;
        }

        void processPayment(double amount) override {
            if (!validatePayment()) {
                cout << "Debit card validation failed.\n";
                return;
            }
            double fee = getTransactionFee(amount);
            cout << "DebitCard Payment: " << amount
                << " | Fee: " << fee << endl;
        }
};

class PayPal : public PaymentMethod {
    private:
        string email;
        string password;

    public:
        PayPal(string e, string p) : email(e), password(p) {}

        bool validatePayment() override {
            cout << "Validating PayPal..." << endl;
            return email.find('@') != string::npos && password.size() >= 6;
        }

        double getTransactionFee(double amount) override {
            return 0.30 + amount * 0.029;
        }

        void processPayment(double amount) override {
            if (!validatePayment()) {
                cout << "PayPal validation failed.\n";
                return;
            }
            double fee = getTransactionFee(amount);
            cout << "PayPal Payment: " << amount
                << " | Fee: " << fee << endl;
        }
};


class Cryptocurrency : public PaymentMethod {
    private:
        string walletAddress;

    public:
        Cryptocurrency(string w) : walletAddress(w) {}

        bool validatePayment() override {
            cout << "Validating Crypto Wallet..." << endl;
            return walletAddress.size() >= 24;
        }

        double getTransactionFee(double amount) override {
            return 0.0005 * amount;
        }

        void processPayment(double amount) override {
            if (!validatePayment()) {
                cout << "Crypto validation failed.\n";
                return;
            }
            double fee = getTransactionFee(amount);
            cout << "Crypto Payment: " << amount
                << " | Fee: " << fee << endl;
        }
};

int main() {
    vector<PaymentMethod*> methods;

    methods.push_back(new CreditCard("1234567890123456", "12/28", "123"));
    methods.push_back(new DebitCard("9876543210987654", "4321"));
    methods.push_back(new PayPal("akrom@example.com", "pass123"));
    methods.push_back(new Cryptocurrency("0xABCDEF0123456789ABCDEF012"));

    for (auto* pm : methods) {
        pm->processPayment(100.0);
        cout << "------------------\n";
    }

    for (auto* pm : methods)
        delete pm;

    return 0;
}
