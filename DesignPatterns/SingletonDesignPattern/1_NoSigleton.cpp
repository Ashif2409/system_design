/*
 * This program demonstrates the **anti-pattern** of Singleton: 
 * It defines a class `NoSingleton` that allows creating multiple objects.
 * 
 * In software design, a **Singleton** is a class that allows only 
 * one instance to exist throughout the program's lifetime.
 * This is achieved by:
 *  - Making the constructor private or protected
 *  - Providing a static method to get the single instance
 * 
 * In this example, the class does NOT enforce Singleton behavior.
 * Thus, multiple instances can be created, each with its own memory address.
 * The program creates two instances and checks if their pointers are equal (they won't be).
 */
#include<iostream>

using namespace std;

class NoSingleton {
public:
    NoSingleton() {
        cout << "Singleton Constructor called. New Object created." << endl;
    }
};

int main() {
    NoSingleton* s1 = new NoSingleton();
    NoSingleton* s2 = new NoSingleton();

    cout << (s1 == s2) << endl;
}