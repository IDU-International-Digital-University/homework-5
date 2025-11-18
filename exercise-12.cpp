#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing Shape\n";
    }
};

class Circle : public Shape {
public:
    int radius;
    Circle(int r) : radius(r) {}

    void draw() override {
        cout << "Drawing Circle with radius " << radius << "\n";
    }
};

// FIXED: pass by reference
void processShape(Shape& s) {
    s.draw();         // Dynamic dispatch works
}

int main() {
    Circle c(5);
    processShape(c);   // Prints Circle version
}
