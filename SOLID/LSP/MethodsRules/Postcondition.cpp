/*
 * This program demonstrates the concept of **Postconditions** and how they relate to the
 * **Liskov Substitution Principle (LSP)** in object-oriented programming.
 *
 * - A **Postcondition** is a condition that must be true after a method is executed.
 * - According to LSP, a subclass must be substitutable for its superclass without
 *   affecting the correctness of the program.
 * - Subclasses are allowed to **strengthen** postconditions (i.e., add more guarantees),
 *   but they must not **weaken** them (i.e., break or reduce expected behavior).
 *
 * In this example:
 *
 * - The `Car` class has a `brake()` method with the postcondition: speed must reduce.
 * - The `HybridCar` class (a subclass of `Car`) overrides the `brake()` method.
 *   It not only reduces speed (same postcondition as `Car`) but also increases battery charge.
 * - Since `HybridCar` strengthens the postcondition (adds an extra effect without breaking the original),
 *   it obeys LSP.
 *
 * In `main()`, a `HybridCar` object is used through a `Car*` pointer, demonstrating that
 * substituting `HybridCar` in place of `Car` does not break client code — a key idea of LSP.
 */

#include <bits/stdc++.h>

using namespace std;

// A Postcondition must be satisfied after a method is executed.
// Subclasses can strengthen the Postcondition but cannot weaken it.

class Car {
protected:
    int speed;    

public:
    Car() {
        speed = 0;
    }
    
    void accelerate() {
        cout << "Accelerating" << endl;
        speed += 20;
    }

    // PostCondition : Speed must reduce after brake
    virtual void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
    }
};

// Subclass can strengthen postcondition - Does not violate LSP
class HybridCar : public Car {
private:
    int charge;

public:
    HybridCar() : Car() {
        charge = 0;
    }

    // PostCondition : Speed must reduce after brake
    // PostCondition : Charge must increase
    void brake() override {
        cout << "Applying brakes" << endl;
        speed -= 20;
        charge += 10;
    }
};

int main() {
    Car* hybridCar = new HybridCar();
    hybridCar->brake();  // Works fine: HybridCar reduces speed and also increases charge.

    // Client feels no difference in substituting HybridCar in place of Car.

    return 0;
}
