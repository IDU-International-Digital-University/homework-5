// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

class Vehicle {
    protected:
        std::string registrationNumber;
        
    public:
        Vehicle(const std::string& reg) : registrationNumber(reg) {};
        
        virtual void startEngine() = 0;
        virtual void stopEngine() = 0;
        
        virtual void refuel() {
            std::cout << "Vehicle refueled...\n";
        };
        
        void getRegistrationNumber() const {
            std::cout << "Registration#: " << registrationNumber;
        };
        
        virtual ~Vehicle() = default;
};


class Car : public Vehicle {
    public:
        Car(const std::string& reg) : Vehicle(reg) {};
        
        void startEngine() override {
            std::cout << "Car engine started\n";
        };
        
        void stopEngine() override {
            std::cout << "Car engine stopped";
        };
        
};

class Motorcycle : public Vehicle {
    public:
        Motorcycle(const std::string& reg) : Vehicle(reg) {};
        
        void startEngine() override {
            std::cout << "Motorcycle engine started\n ";

        };
        
        void stopEngine() override {
            std::cout << "Motorcycle engine stopped\n";
        };
};


class ElectricCar : public Vehicle {
    public:
        ElectricCar(const std::string& reg) : Vehicle(reg) {};
        
        void startEngine() override {
            std::cout << "Electric car powered on\n";
        };
        
        void stopEngine() override {
            std::cout << "Electric car powered off\n";
        };
        
        void refuel() override {
            std::cout << "Electric car is charging...\n";
        };
};

int main() {
    Vehicle* v1 = new Car("sldjfkljsd");
    Vehicle* v2 = new Motorcycle("vlkjskldjkl");
    Vehicle* v3 = new ElectricCar("lkdslj9");
    
    v1->startEngine();
    v1->refuel();
    v1->getRegistrationNumber();
    
    v3->refuel();
    
    delete v1;
    delete v2;
    delete v2;
    return 0;
}