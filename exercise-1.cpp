#include <iostream>
#include <string>
using namespace std;

class Animal {
    protected:
        string name;
        int age;

    public:
        Animal(string n, int a) : name(n), age(a) {}

        void eat() {
            cout << name << " is eating." << endl;
        }

        void sleep() {
            cout << name << " is sleeping." << endl;
        }

        virtual void makeSound() {
            cout << name << " makes a sound." << endl;
        }
};

class Dog : public Animal {
    public:
        Dog(string n, int a) : Animal(n, a) {}

        void makeSound() override {
            cout << name << " says: Woof! Woof!" << endl;
        }

        void fetch() {
            cout << name << " is fetching the ball!" << endl;
        }
};

class Cat : public Animal {
    public:
        Cat(string n, int a) : Animal(n, a) {}

        void makeSound() override {
            cout << name << " says: Meow!" << endl;
        }

        void scratch() {
            cout << name << " is scratching the furniture!" << endl;
        }
};

class Bird : public Animal {
    public:
        Bird(string n, int a) : Animal(n, a) {}

        void makeSound() override {
            cout << name << " says: Tweet!" << endl;
        }

        void fly() {
            cout << name << " is flying in the sky!" << endl;
        }
};

int main() {
    Dog dog("Buddy", 3);
    Cat cat("Whiskers", 2);
    Bird bird("Chirpy", 1);
    dog.eat();
    dog.makeSound();
    dog.fetch();
    cout << endl;
    cat.sleep();
    cat.makeSound();
    cat.scratch();
    cout << endl;
    bird.eat();
    bird.makeSound();
    bird.fly();

    return 0;
}
