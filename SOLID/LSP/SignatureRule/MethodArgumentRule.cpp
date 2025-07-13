/*
 * This program demonstrates the **Method Argument Rule** related to
 * the **Liskov Substitution Principle (LSP)** in object-oriented programming.
 *
 * 📌 Method Argument Rule:
 *   In order to maintain substitutability (LSP), a subclass must not require
 *   *stricter or narrower argument types* than the base class.
 *
 * ✅ In simpler terms:
 *   - A subclass can accept **the same** or **more general (wider)** arguments.
 *   - But it should NOT demand **more specific** argument types that the base class doesn't.
 *
 * ✅ C++ enforces this automatically by requiring **identical function signatures**
 * when overriding a method using `override`.
 *
 * 🔍 In this example:
 * - `Parent::print(string)` is overridden by `Child::print(string)` using the same argument type.
 * - The `Client` calls `p->print("Hello")` on a `Parent*`, but it's safe to pass a `Child` object too.
 *   This demonstrates that `Child` is a valid substitute for `Parent`, preserving LSP.
 *
 * 🧠 If `Child::print` had changed the argument to something narrower (e.g., `const char*`),
 *   it would not override the method — and it would **break substitutability**.
 */

#include <iostream>

using namespace std;

// Method Argument Rule:
// Subtype method arguments can be the same or more general than the base class.
// C++ enforces this by requiring exact method signatures for overriding.

class Parent {
public:
    virtual void print(string msg) {
        cout << "Parent: " << msg << endl;
    }
};

class Child : public Parent {
public:
    void print(string msg) override { 
        cout << "Child: " << msg << endl;
    }
};

// Client expects any object that can print a string message.
class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }  

    void printMsg() {
        p->print("Hello");
    }
};

int main() {
    Parent* parent = new Parent();
    Parent* child = new Child();

    // Client using a Parent object
    // Client* client = new Client(parent);

    // Client using a Child object (valid substitution)
    Client* client = new Client(child);

    client->printMsg();

    return 0;
}
