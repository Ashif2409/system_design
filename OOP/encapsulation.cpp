#include <bits/stdc++.h>
using namespace std;

class sportscar
{
private:
    // Private member variables
    bool isEngineOn;
    int speed;
    int currentGear;
    string tyre;
public:
    sportscar()  {
        this->isEngineOn = false;
        this->speed = 0;
        this->currentGear = 0;
        this->tyre = "MRF";
    }

    void getSpeed() {
        cout << "Current speed: " << this->speed << endl;
    }

    void getTyre() {
        cout << "Current tyre: " << this->tyre << endl;
    }

    void setTyre(string tyre) {
        //we can add validation here if needed
        this->tyre = tyre;
        cout << "Tyre changed to: " << this->tyre << endl;
    }
    void start()  {
        this->isEngineOn = true;
        cout << "Sportscar started." << endl;
    }

    void stop()  {
        if(this->isEngineOn) {
            this->isEngineOn = false;
        }
        else {
            cout << "Sportscar is already stopped." << endl;
            return;
        }
        cout << "Sportscar stopped." << endl;
    }

    void accelerate(int accelerationValue)  {
        if(!this->isEngineOn) {
            cout << "Cannot accelerate. Start the sportscar first." << endl;
            return;
        }
        this->speed += accelerationValue;
        cout << "Sportscar accelerating...current speed: "<<this->speed << endl;
    }

    void gearShift(int gear)  {
        if(!this->isEngineOn) {
            cout << "Cannot shift gears. Start the sportscar first." << endl;
            return;
        }
    this->currentGear = gear;
        cout << "Sportscar gear shifted. Current gair level: "<<this->currentGear << endl;
    }
};

int main() {
    sportscar* myCar = new sportscar();
    myCar->start();
    myCar->accelerate(50);
    myCar->gearShift(3);
    myCar->getSpeed();
    myCar->getTyre();
    myCar->setTyre("Bridgestone");
    myCar->getTyre();
    myCar->stop();
    delete myCar; 
    return 0;
}