/*
 * 🧱 Interface Segregation Principle (ISP) - SOLID Principle
 *
 * ✅ Principle:
 *   Clients should not be forced to depend on interfaces they do not use.
 *   Instead of having a large interface for all shapes (2D + 3D),
 *   it’s better to **split interfaces** based on functionality (e.g., 2D area vs 3D volume).
 *
 * ✅ This example follows ISP correctly by:
 *   - Creating two separate interfaces:
 *       1. `TwoDimensionalShape` with only `area()`
 *       2. `ThreeDimensionalShape` with both `area()` and `volume()`
 *   - Implementing only what each shape needs:
 *       - `Square` and `Rectangle` implement only 2D interface.
 *       - `Cube` implements the 3D interface.
 *
 * ❌ What would violate ISP?
 *   If we had a single interface with both `area()` and `volume()`, 
 *   then 2D shapes like `Square` and `Rectangle` would be forced to implement `volume()` unnecessarily.
 *
 * 💡 In short, ISP promotes designing small, specific interfaces that are relevant to the client.
 */

#include <iostream>

using namespace std;

// Interface for 2D shapes (Only area is needed)
class TwoDimensionalShape {
public:
    virtual double area() = 0;
};

// Interface for 3D shapes (Requires both area and volume)
class ThreeDimensionalShape {
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// ✅ Square only implements the 2D shape interface
class Square : public TwoDimensionalShape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }
};

// ✅ Rectangle only implements the 2D shape interface
class Rectangle : public TwoDimensionalShape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};

// ✅ Cube implements the 3D shape interface (area + volume)
class Cube : public ThreeDimensionalShape {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }
};

int main() {
    TwoDimensionalShape* square = new Square(5);
    TwoDimensionalShape* rectangle = new Rectangle(4, 6);
    ThreeDimensionalShape* cube = new Cube(3);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    return 0;
}
