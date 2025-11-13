#include <iostream>
#include <string>
using namespace std;


class Calculator {
    public:
        int add(int a, int b) {
            cout << "Adding two integers: ";
            return a + b;
        };

        int add(int a, int b, int c) {
            cout << "Adding three integers: ";
            return a + b + c;
        };

        double add(double a , double b) {
            cout << "Adding two doubles: ";
            return a + b;
        };

        string add(const string& a , const string& b) {
            cout << "Constenating two strings: ";
            return a + b;
        };
};

int main() {
    Calculator calculator;

    cout << calculator.add(3, 5) << endl;
    cout << calculator.add(43, 23, 45) << endl;
    cout << calculator.add(4.2, 5.5) << endl;
    cout << calculator.add("Hello  ", "World!") << endl;

    return 0;
};