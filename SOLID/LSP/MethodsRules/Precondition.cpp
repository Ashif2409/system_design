/*
 * This program demonstrates the concept of **Preconditions** in object-oriented programming,
 * and how they relate to the **Liskov Substitution Principle (LSP)**.
 *
 * - A **Precondition** is a condition that must be true before a method is called.
 * - According to LSP, a subclass must be usable anywhere its superclass is expected,
 *   without changing the correctness of the program.
 * - Subclasses are allowed to **weaken** preconditions (i.e., accept more input cases),
 *   but must not **strengthen** them (i.e., reject cases that the base class allows).
 *
 * In this example:
 *
 * - The `User` class requires a password of **at least 8 characters**.
 * - The `AdminUser` subclass relaxes this rule, allowing passwords of **at least 6 characters**.
 * - This is valid under LSP because the subclass **weakens** the precondition.
 *
 * In `main()`, an `AdminUser` object is used through a `User*` pointer.
 * The password `"Admin1"` (6 characters) would be rejected by `User`, but is accepted by `AdminUser`.
 * This shows that the subclass still works when substituted in place of the base class,
 * maintaining the spirit of LSP.
 */

#include <bits/stdc++.h>

using namespace std;

// A Precondition must be satisfied before a method can be executed.
// Subclasses can weaken the Precondition but cannot strengthen it.

class User {
public:
    // Precondition: Password must be at least 8 characters long
    virtual void setPassword(string password) {
        if (password.length() < 8) {
            throw invalid_argument("Password must be at least 8 characters long!");
        }
        cout << "Password set successfully" << endl;
    }
};

class AdminUser : public User {
public:
    // Precondition: Password must be at least 6 characters
    void setPassword(string password) override {
        if (password.length() < 6) {
            throw invalid_argument("Password must be at least 6 characters long!");
        }
        cout << "Password set successfully" << endl;
    }
};

int main() {
    User* user = new AdminUser();
    user->setPassword("Admin1");  // Works fine: AdminUser allows shorter passwords

    return 0;
}
