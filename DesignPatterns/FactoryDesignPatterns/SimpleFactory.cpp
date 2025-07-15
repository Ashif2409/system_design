//       +---------------------+
//       |   <<abstract>>      |
//       |      Product        |
//       +---------------------+
//       | +operation()        |
//       +---------------------+
//               ^
//               |
//     +---------+----------+
//     |         |          |
// +----------+ +----------+ +-----------+
// |ProductA  | |ProductB  | |ProductC   |  (etc)
// +----------+ +----------+ +-----------+
// |operation()| |operation()| |operation()|
// +----------+ +----------+ +-----------+

//       +---------------------+
//       |    Factory          |
//       +---------------------+
//       | +createProduct(type): Product |
//       +---------------------+
//              |
//              v
//       (creates ProductA/B/C)
/*
 * Simple Factory Pattern Example
 * -----------------------------
 * The Simple Factory Pattern is a way to create objects without exposing the creation logic to the client.
 * You just tell the factory what you want (by passing a type), and it gives you the correct object.
 * 
 * In this example, BurgerFactory creates different types of Burger objects based on a string input.
 * This makes the code cleaner and lets you add new burger types more easily later.
 */

 #include <iostream>

using namespace std;

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

class BurgerFactory {
public:
    Burger* createBurger(string& type) {
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

int main() {
    string type = "standard";

    BurgerFactory* myBurgerFactory = new BurgerFactory();

    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();

    return 0;
}


