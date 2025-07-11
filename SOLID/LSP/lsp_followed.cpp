// L: Liskov Substitution Principle (LSP)
// Subtypes must be substitutable for their base types without breaking the program.
//
//  This code follows LSP:
// - `WithdrawableAccount` and `DepositOnlyAccount` are separated.
// - `FixedTermAccount` does NOT inherit `WithdrawableAccount`, so it doesn’t pretend to support withdrawal.
//
//  What if we had only one abstract base class like this:
//     class Account {
//         virtual void deposit(double) = 0;
//         virtual void withdraw(double) = 0;
//     }
//
//  Issue:
// - Then `FixedTermAccount` would be forced to implement `withdraw()`,
//   even though fixed deposit accounts should NOT allow withdrawals.
// - You might write dummy code like:
//     void withdraw(double) { throw runtime_error("Not allowed"); }
// - Now, if some client calls `withdraw()` assuming it always works,
//   it could cause runtime crashes or unexpected behavior.
//
//  This would break LSP because the subclass (FixedTermAccount) wouldn't behave like the base class promises.

#include <bits/stdc++.h>
using namespace std;


class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount {
private:
    double balance;

public:
    SavingAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
    private:
        double balance;
    
    public:
        CurrentAccount() { 
            balance = 0; 
        }
    
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
        }
    
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in Current Account!\n";
            }
        }
    };

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

class BankClient {
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
    BankClient( vector<WithdrawableAccount*> withdrawableAccounts, 
        vector<DepositOnlyAccount*> depositOnlyAccounts) { 
        this->withdrawableAccounts = withdrawableAccounts; 
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions() {
        for (WithdrawableAccount* acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500); 
        }
        for (DepositOnlyAccount* acc : depositOnlyAccounts) {
            acc->deposit(5000);
        }
    }
};

int main() {
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient (withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;
}

    
    
    