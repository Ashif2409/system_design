/*
 * This program demonstrates the classic **Singleton design pattern** in C++.
 *
 * -----------------
 * **Singleton Pattern Definition:**
 * The Singleton pattern ensures that a class has only one instance and provides
 * a global point of access to it. It is commonly used when exactly one object is
 * needed to coordinate actions across the system (e.g., configuration managers,
 * logger classes, etc).
 *
 * -----------------
 * **How this code works:**
 * - The class `Singleton` has a private static pointer `instance` which holds
 *   the sole instance of the class.
 * - The constructor is private, so objects cannot be created from outside.
 * - The static method `getInstance()` checks if the instance is `nullptr`. If so,
 *   it creates the singleton instance and returns it; otherwise, it just returns
 *   the existing one.
 * - This ensures that only one object is ever created.
 *
 * -----------------
 * **Thread Safety Issue:**
 * - This implementation is **NOT thread-safe**. In a multi-threaded environment,
 *   it is possible that two threads call `getInstance()` at the same time and both
 *   see `instance` as `nullptr`, resulting in two separate instances being created.
 * - To make this Singleton thread-safe, you need to add **locking/mutex** in the
 *   `getInstance()` method, so that only one thread can create the instance at a time.
 * - In C++11 and later, you can also use a local static variable in the function,
 *   which is guaranteed to be initialized in a thread-safe way.
 * - Another method is **Double-Checked Locking** with a mutex, but it’s more complex.
 *
 * -----------------
 * **Summary:**
 * - This code is a basic Singleton (not thread-safe).
 * - In single-threaded apps, it works perfectly.
 * - For multi-threaded apps, use locking or C++11 local statics for thread safety!
 */

#include<iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    // Private constructor to prevent direct instantiation
    Singleton() {
        cout << "Singleton Constructor called" << endl;
    }

public:
    // Static method to get the unique instance
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    // This prints 1 (true), since s1 and s2 point to the same Singleton object.
    cout << (s1 == s2) << endl;
}
