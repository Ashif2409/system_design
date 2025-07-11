// Polymorphism : poly means many and morph means form, polymorphism means many form 
//compile time: function overloading
//run time: function overriding.

#include <bits/stdc++.h>
using namespace std;

// Abstract Base Class
class Car {
protected:
    bool isEngineOn = true;
    int speed = 0;
    int currentGear = 0;
    string brand;
    string model;

public:
    void addBrandAndModel(string brand, string model) {
        this->brand = brand;
        this->model = model;
        cout << "Brand set to: " << this->brand << endl;
        cout << "Model set to: " << this->model << endl;
    }

    virtual void accelerate() = 0; // Pure virtual function
};

// Derived class: ManualCar
class ManualCar : public Car {
private:
    int gearCount;

public:
    ManualCar() {
        this->gearCount = 5;
        this->currentGear = 0;
    }

    void accelerate() override {
        if (!this->isEngineOn) {
            cout << "Cannot accelerate. Start the manual car first." << endl;
            return;
        }
        this->speed += 15;
        cout << "Manual car accelerating... current speed: " << this->speed << endl;
    }

    // Overloaded method (compile-time polymorphism)
    void accelerate(int accelerationValue) {
        if (!this->isEngineOn) {
            cout << "Cannot accelerate. Start the manual car first." << endl;
            return;
        }
        this->speed += accelerationValue;
        cout << "Manual car accelerating... current speed: " << this->speed << endl;
    }

    void shiftGear(int gear) {
        if (gear < 1 || gear > gearCount) {
            cout << "Invalid gear selection." << endl;
            return;
        }
        this->currentGear = gear;
        cout << "Manual car shifted to gear: " << this->currentGear << endl;
    }
};

// Derived class: AutomaticCar
class AutomaticCar : public Car {
private:
    int batteryLevel = 0;

public:
    void chargeBattery(int amount) {
        if (amount < 0) {
            cout << "Invalid battery charge amount." << endl;
            return;
        }
        this->batteryLevel += amount;
        cout << "Battery charged. Current level: " << this->batteryLevel << "%" << endl;
    }

    void accelerate() override {
        if (!this->isEngineOn) {
            cout << "Cannot accelerate. Start the automatic car first." << endl;
            return;
        }
        this->speed += 10;
        this->batteryLevel -= 5;

        if (this->batteryLevel < 0) {
            cout << "Battery depleted. Please charge the car." << endl;
            return;
        }

        cout << "Automatic car accelerating... current speed: " << this->speed << endl;
    }
};

// Main function demonstrating polymorphism
int main() {
    // Runtime polymorphism using base class pointers
    ManualCar* car1 = new ManualCar();
    car1->addBrandAndModel("Honda", "Civic");
    car1->accelerate(); // Calls ManualCar's accelerate()
    car1->shiftGear(3); // Accessing derived-specific function
    car1->accelerate(20); // Overloaded method
    delete car1;

    AutomaticCar* car2 = new AutomaticCar();
    car2->addBrandAndModel("Toyota", "Corolla");
    car2->chargeBattery(20); // Accessing derived-specific function
    car2->accelerate(); // Calls AutomaticCar's accelerate()
    delete car2;

    return 0;
}
