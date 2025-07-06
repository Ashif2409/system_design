#include<bits/stdc++.h>
using namespace std;

class car
{
public:
    virtual void start() = 0; // pure virtual function
    virtual void stop() = 0;  // pure virtual function
    virtual void accelerate(int accelerationValue) = 0; // pure virtual function
    virtual void gearShift(int cnt) = 0; // pure virtual function
    virtual ~car() {} // virtual destructor
};

class sportscar : public car
{
public:
    bool isEngineOn;
    int accelerationLevel;
    int currentGear;
    sportscar()  {
        this->isEngineOn = false;
        this->accelerationLevel = 0;
        this->currentGear = 0;
    }
    void start() override {
        this->isEngineOn = true;
        cout << "Sportscar started." << endl;
    }

    void stop() override {
        if(this->isEngineOn) {
            this->isEngineOn = false;
        }
        else {
            cout << "Sportscar is already stopped." << endl;
            return;
        }
        cout << "Sportscar stopped." << endl;
    }

    void accelerate(int accelerationValue) override {
        if(!this->isEngineOn) {
            cout << "Cannot accelerate. Start the sportscar first." << endl;
            return;
        }
        this->accelerationLevel += accelerationValue;
        cout << "Sportscar accelerating...current acceleration: "<<this->accelerationLevel << endl;
    }

    void gearShift(int gear) override {
        if(!this->isEngineOn) {
            cout << "Cannot shift gears. Start the sportscar first." << endl;
            return;
        }
    this->currentGear = gear;
        cout << "Sportscar gear shifted. Current gair level: "<<this->currentGear << endl;
    }
};

int main() {
    car* myCar = new sportscar();
    myCar->start();
    myCar->accelerate(50);
    myCar->gearShift(3);
    myCar->stop();
    delete myCar; 
    return 0;
}