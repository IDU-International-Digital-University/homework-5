// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    protected:
        char* name;
        
    public:
        Employee(const char* n) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        };
        
        ~Employee() {
            cout << "Employee destructor";
            delete[] name;
        };
};

class Manager: public Employee {
    private:
        char* department;
        
    public:
        Manager(const char* n, const char* d) : Employee(n) {
            department = new char[strlen(d) + 1];
            strcpy(department, d);
        };
         ~Manager() {
             cout << "Manager destructor\n";
             delete[] department;
         };
};

int main() {
    // Write C++ code here
    Employee* e = new Manager("Akrom", "Python");
    delete e;

    return 0;
}




