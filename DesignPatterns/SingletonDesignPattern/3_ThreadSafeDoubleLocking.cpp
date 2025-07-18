/*
 * This program demonstrates a **thread-safe Singleton pattern**
 * using the **Double-Checked Locking** method with a `std::mutex`.
 *
 * -----------------
 * **Singleton Pattern Recap:**
 * - Ensures only one instance of a class is created during the program’s lifetime.
 * - Provides a global access point to that instance.
 * - Used in scenarios where centralized management or coordination is needed,
 *   such as configuration, logging, connection pooling, etc.
 *
 * -----------------
 * **Thread Safety Issue in Classic Singleton:**
 * - In a multi-threaded program, two threads could both enter `getInstance()`
 *   at the same time when `instance == nullptr` and create two objects, breaking
 *   the Singleton guarantee.
 *
 * -----------------
 * **How Double-Checked Locking Solves This:**
 * - First, check if the instance is `nullptr` without locking (for speed).
 * - If it is, acquire a lock and check again.
 * - Only the first thread that acquires the lock and finds `instance` still
 *   `nullptr` creates the Singleton object.
 * - Subsequent calls skip locking entirely once the instance exists,
 *   ensuring high performance in most cases.
 *
 * - Note: Double-checked locking requires C++11 or later, because of memory
 *   model improvements and guarantees for static/local variables and atomics.
 *   In pre-C++11, this pattern can have subtle bugs!
 *
 * -----------------
 * **Key Points:**
 * - Use `std::mutex` for locking.
 * - Thread-safe, efficient Singleton implementation for most use cases.
 * - This code works correctly in C++11 and newer.
 */

#include<iostream>
#include<mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    // Private constructor prevents direct instantiation.
    Singleton() {
        cout << "Singleton Constructor Called!" << endl;
    }

public:
    // Thread-safe, double-checked locking Singleton accessor.
    static Singleton* getInstance() {
        if (instance == nullptr) {               // First check (without locking)
            lock_guard<mutex> lock(mtx);         // Lock only when necessary
            if (instance == nullptr) {           // Second check (with lock)
                instance = new Singleton();
            }
        }
        return instance;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    // Prints 1 (true) since s1 and s2 point to the same Singleton instance.
    cout << (s1 == s2) << endl;
}
