/*********************************************************
 * Inheritance (Association): 
 * Definition: "Inheritance is an 'is-a' relationship where 
 * a class derives properties from another class."
 * 
 *   +-----------+
 *   |  Animal   |
 *   +-----------+
 *         ^
 *         |
 *   +-----------+
 *   |   Dog     |
 *   +-----------+
 *
 * Simple use: Dog is an Animal.
 *********************************************************/


 #include <bits/stdc++.h>
using namespace std;

// Base class
class Animal {
public:
    void speak() { cout << "Animal speaks." << endl; }
};

// Derived class
class Dog : public Animal {
public:
    void speak() { cout << "Dog barks." << endl; }
};

int main() {
    Animal a;
    a.speak();    // Animal speaks.

    Dog d;
    d.speak();    // Dog barks.

    // Inheritance association: Dog is an Animal.
    Animal* ptr = &d;
    ptr->speak(); // Dog barks. (if virtual, else Animal speaks)

    return 0;
}
