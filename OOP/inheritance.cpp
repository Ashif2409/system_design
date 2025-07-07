// Inheritance is the mechanism by which one class acquires the properties and behaviors of another class.
#include <bits/stdc++.h>
using namespace std;

class Car
{
    protected:
        bool isEngineOn;
        int speed;
        int currentGear;
        string brand;
        string model;
    public:
        void addBrandAndModel(string brand,string model) {
            this->brand = brand;
            this->model = model;
            cout << "Brand set to: " << this->brand << endl;
            cout << "Model set to: " << this->model << endl;
        }

};

class ManualCar: public Car{
    private:
        int gearCount;
    public:
        ManualCar() {
            this->gearCount = 5; // Default gear count for manual cars
            this->currentGear = 0; // Start in first gear
        }
        void shiftGear(int gear) {
            if(gear < 1 || gear > gearCount) {
                cout << "Invalid gear selection." << endl;
                return;
            }
            this->currentGear = gear;
            cout << "Manual car shifted to gear: " << this->currentGear << endl;
        }
} ;

class AutomaticCar: public Car {
    private:
        int batteryLevel;
    public:
        void chargeBattery(int amount) {
            if(amount < 0) {
                cout << "Invalid battery charge amount." << endl;
                return;
            }
            this->batteryLevel += amount;
            cout << "Battery charged. Current level: " << this->batteryLevel << "%" << endl;
        }
};

int main() {
    ManualCar *myManualCar=new ManualCar();
    myManualCar->addBrandAndModel("Honda", "Civic");
    myManualCar->shiftGear(3);
    delete myManualCar;

    AutomaticCar *myAutomaticCar=new AutomaticCar();
    myAutomaticCar->addBrandAndModel("Toyota", "Corolla");
    myAutomaticCar->chargeBattery(20);
    delete myAutomaticCar;
    return 0;
}
