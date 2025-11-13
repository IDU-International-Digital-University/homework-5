#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    // Virtual methods enable runtime polymorphism
    virtual double area() const = 0;        // Pure virtual function
    virtual double perimeter() const = 0;   // Pure virtual function
    virtual void draw() const = 0;          // Pure virtual function

    // Virtual destructor ensures proper cleanup of derived objects
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void draw() const override {
        cout << "Drawing a Circle (radius = " << radius << ")" << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void draw() const override {
        cout << "Drawing a Rectangle (" << width << " x " << height << ")" << endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double a, b, c; // sides

public:
    Triangle(double side1, double side2, double side3)
        : a(side1), b(side2), c(side3) {}

    double area() const override {
        double s = (a + b + c) / 2; // semi-perimeter
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }

    void draw() const override {
        cout << "Drawing a Triangle (sides = " << a << ", " << b << ", " << c << ")" << endl;
    }
};

int main() {
    // Create vector of base class pointers
    vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 4.0, 5.0));

    // Polymorphic behavior
    for (Shape* shape : shapes) {
        shape->draw();
        cout << "  Area: " << shape->area() << endl;
        cout << "  Perimeter: " << shape->perimeter() << endl;
        cout << "---------------------------" << endl;
    }

    // Clean up
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
