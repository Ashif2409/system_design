/*
 * This program demonstrates the concept of **Class Invariants** and how they relate to
 * the **Liskov Substitution Principle (LSP)** in object-oriented programming.
 *
 * - A **class invariant** is a condition that must always be true for an object
 *   of that class — during and after any operation on it.
 * - Subclasses must not break the invariant defined in the base class.
 * - According to LSP, if a subclass violates the base class's invariant,
 *   it can lead to incorrect or unsafe behavior when used polymorphically.
 *
 * In this example:
 * - The `BankAccount` class enforces an invariant: **balance must never be negative**.
 * - It throws an error in `withdraw()` if the balance would go below zero.
 * - The `CheatAccount` subclass overrides `withdraw()` and allows negative balances,
 *   which **breaks the invariant**.
 *
 * This is a clear **violation of LSP**: A `CheatAccount` object used where a `BankAccount*`
 * is expected would allow invalid states (negative balances), violating client expectations.
 *
 * ✅ Key Rule: Subclasses must maintain or strengthen the invariants of their base class,
 * not weaken or remove them.
 */

#include <iostream>

using namespace std;

// Invariant: Balance cannot be negative
class BankAccount {
protected:
    double balance;

public:
    BankAccount(double b) {
        if (b < 0) throw invalid_argument("Balance can't be negative");
        balance = b;
    }

    virtual void withdraw(double amount) {
        if (balance - amount < 0) throw runtime_error("Insufficient funds");
        balance -= amount;
        cout << "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

// ❌ Breaks invariant: Allows negative balance (violates LSP)
class CheatAccount : public BankAccount {
public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        balance -= amount; // Invalid: allows negative balance
        cout << "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);  // Valid: balance = 0

    // Using CheatAccount here would break the invariant!
    // BankAccount* badAccount = new CheatAccount(50);
    // badAccount->withdraw(100); // Would allow balance = -50 (INVALID)

    return 0;
}
