/*
 * This program demonstrates the **Return Type Rule** (also called **covariant return types**) 
 * in the context of the **Liskov Substitution Principle (LSP)** in object-oriented programming.
 *
 * 📌 Return Type Rule:
 * When overriding a method, the subclass can return:
 *   ✅ The **same type** as the base class method
 *   ✅ A **subclass (narrower type)** of the return type declared in the base class
 *
 * 🔍 This is called **return type covariance**, and C++ **supports and enforces** this.
 * It ensures that subclass methods can safely return more specific results than the base method.
 *
 * 💡 In this example:
 * - `Parent::getAnimal()` returns a pointer to `Animal`.
 * - `Child::getAnimal()` overrides it and returns a pointer to `Dog`, which is a subtype of `Animal`.
 * - The client interacts with `Parent*` but gets a `Dog*`, which is valid and expected — preserving LSP.
 *
 * ✅ This ensures that subclasses can be substituted for base classes without surprising behavior,
 * and clients relying on the base type still work correctly when receiving subtypes.
 */

#include <iostream>

using namespace std;

// Return Type Rule: Subclass method return type must be same or narrower (covariant return type)

class Animal {
    // Common methods for all animals
};

class Dog : public Animal {
    // Specific methods for dogs
};

class Parent {
public:
    virtual Animal* getAnimal() {
        cout << "Parent: Returning Animal instance" << endl;
        return new Animal();
    }
};

class Child : public Parent {
public:
    // Covariant return type (Dog* is a subclass of Animal*)
    Animal* getAnimal() override {
        cout << "Child: Returning Dog instance" << endl;
        return new Dog();
    }
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }

    void takeAnimal() {
        p->getAnimal();  // Works regardless of whether p is Parent or Child
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(child);   // ✅ Valid: Child returns Dog* where Animal* is expected
    // Client* client = new Client(parent); // Also valid

    client->takeAnimal();

    return 0;
}
