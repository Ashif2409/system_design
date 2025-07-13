/*
 * This program demonstrates the **Exception Rule** related to the
 * **Liskov Substitution Principle (LSP)** in object-oriented programming.
 *
 * 🔁 LSP states that: Subtypes must be substitutable for their base types without altering correctness.
 *
 * 📌 Exception Rule:
 * When overriding a method in a subclass, the **subclass should not throw broader or new exceptions**
 * that the parent class does not throw. It may:
 *   - throw **fewer exceptions**, or
 *   - throw **more specific (narrower)** exceptions.
 *
 * ❗ In C++, the compiler does **not enforce** this rule, so violating it won’t result in a compile-time error,
 * but it **can break client expectations at runtime**.
 *
 * ✅ In this example:
 * - `Parent::getValue()` throws `std::logic_error`.
 * - `Child::getValue()` throws `std::out_of_range`, which is a **narrower** type derived from `logic_error`.
 *   ✔ This is allowed and safe.
 *
 * ❌ If the child method throws a `std::runtime_error` (which is **not** a subclass of `logic_error`),
 *    then any `catch(logic_error)` in the client will **miss** that exception, violating LSP expectations.
 */

#include <iostream>

using namespace std;

// Exception Rule:
// A subclass should throw fewer or narrower exceptions than the base class.
// C++ does not enforce this at compile time.

class Parent {
public:
    virtual void getValue() noexcept(false) {  // Base class throws logic_error
        throw logic_error("Parent error");
    }
};

class Child : public Parent {
public:
    void getValue() noexcept(false) override {  // Subclass throws out_of_range (a narrower exception)
        throw out_of_range("Child error");       // ✅ OK: out_of_range is a logic_error
        // throw runtime_error("Child Error");   // ❌ Not OK: runtime_error is NOT a logic_error
    }
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }

    void takeValue() {
        try {
            p->getValue();
        }
        catch(const logic_error& e) {
            cout << "Logic error exception occurred: " << e.what() << endl;
        }
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(parent);
    // Client* client = new Client(child);  // ✅ Works if child throws logic_error or its subclass

    client->takeValue();

    return 0;
}
