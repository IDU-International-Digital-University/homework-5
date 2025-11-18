#include <iostream>
#include <string>
using namespace std;

class Device {
    public:
        string model;

        Device() : model("Generic Device") {}
};


class Printer : virtual public Device {
    public:
        void printDocument() {
            cout << "Printing from Printer\n";
        }
    };

class Scanner : virtual public Device {
    public:
        void scanDocument() {
            cout << "Scanning from Scanner\n";
        }
};

class AllInOne : public Printer, public Scanner {
    public:
        void showModel() {
            cout << "Model: " << model << endl;
        }
};

int main() {
    AllInOne aio;

    aio.model = "HP All-In-One";

    aio.printDocument();
    aio.scanDocument();
    aio.showModel();
}
