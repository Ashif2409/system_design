/*
 * This program demonstrates the concept of the **History Constraint** and how violating it
 * breaks the **Liskov Substitution Principle (LSP)** in object-oriented design.
 *
 * 📌 History Constraint:
 * If a base class allows certain operations (like `withdraw()`), then the subclass should
 * **not disallow or remove** that operation. Subclasses should not change the expected
 * behavior or allowable state transitions of the base class.
 *
 * 🔍 In this example:
 * - `BankAccount` has a method `withdraw()` that reduces balance, if sufficient funds exist.
 * - According to the base class contract, **withdraw is always allowed** as long as there's enough balance.
 * - The subclass `FixedDepositAccount` overrides `withdraw()` and **completely disallows it**.
 * 
 * ❌ This breaks the history constraint:
 * A `FixedDepositAccount` object is no longer a proper substitute for `BankAccount`,
 * because it restricts an operation that was always allowed in the base class.
 * 
 * 🧠 Violation of LSP:
 * Client code using `BankAccount*` might expect `withdraw()` to work,
 * but passing a `FixedDepositAccount` instead breaks that expectation.
 */

#include <iostream>

using namespace std;

// Subclass methods should not forbid state changes that the base class allows

class BankAccount {
protected:
    double balance;

public:
    BankAccount(double b) {
        if (b < 0) throw invalid_argument("Balance can't be negative");
        balance = b;
    }

    // History Constraint: Withdraw should always be allowed if balance is sufficient
    virtual void withdraw(double amount) {
        if (balance - amount < 0) throw runtime_error("Insufficient funds");
        balance -= amount;
        cout << "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

// ❌ Violates LSP - Breaks history constraint by disallowing withdraw
class FixedDepositAccount : public BankAccount {
public:
    FixedDepositAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        throw runtime_error("Withdraw not allowed in Fixed Deposit");
    }
};

int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);  // Works fine

    // This would compile but fail at runtime due to LSP violation:
    // BankAccount* fdAccount = new FixedDepositAccount(100);
    // fdAccount->withdraw(50);  // Throws exception unexpectedly

    return 0;
}
