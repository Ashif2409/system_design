// The Factory Method Pattern defines an interface for creating an object, but lets subclasses decide which class to instantiate. 
// Instead of calling a constructor directly, you call a factory method, which creates objects for you.
// This pattern is useful when you have a super class (like BurgerFactory) and want to let subclasses 
// (SinghBurger, KingBurger) decide which product (Burger and its types) to make.

//      +-------------------+
//      |  <<interface>>    |
//      |   BurgerFactory   |<-----------------+
//      +-------------------+                  |
//      | +createBurger()   |                  |
//      +-------------------+                  |
//              ^                              |
//              |                              |
//    +--------------------+         +---------------------+
//    |   SinghBurger      |         |    KingBurger       |
//    +--------------------+         +---------------------+
//    | +createBurger()    |         | +createBurger()     |
//    +--------------------+         +---------------------+

//      +-------------------+
//      |  <<interface>>    |
//      |     Burger        |<---------------+
//      +-------------------+                |
//      | +prepare()        |                |
//      +-------------------+                |
//              ^                            |
//   +--------------------+     +----------------------+
//   |   BasicBurger      |     |   BasicWheatBurger   |
//   +--------------------+     +----------------------+
//   | +prepare()         |     | +prepare()           |
//   +--------------------+     +----------------------+
//   ... (other concrete products)

#include <iostream>

using namespace std;

// Product Class and subclasses
class Burger {
public:
    virtual void prepare() = 0;  // Pure virtual function
    virtual ~Burger() {}  // Virtual destructor
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Wheat Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};


// Factory and its concretions
class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
};

class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        } else if (type == "premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

int main() {
    string type = "basic";

    BurgerFactory* myFactory = new SinghBurger();

    Burger* burger = myFactory->createBurger(type);

    burger->prepare();

    return 0;
}



