/*
 * 🔄 Dependency Inversion Principle (DIP) — SOLID Principle
 *
 * ✅ Principle:
 *   High-level modules should not depend on low-level modules.
 *   Both should depend on abstractions.
 *   Abstractions should not depend on details. Details should depend on abstractions.
 *
 * 🧠 In simple terms:
 *   Instead of directly depending on MySQL or MongoDB,
 *   the high-level logic (UserService) depends on an interface (Database),
 *   and the concrete databases implement that interface.
 *
 * ✅ This ensures loose coupling, flexibility, and easier testing or swapping implementations.
 *
 * 🔧 This example demonstrates DIP using:
 *   - `Database` (an abstract interface)
 *   - `MySQLDatabase` and `MongoDBDatabase` (low-level modules implementing `Database`)
 *   - `UserService` (high-level module depending on `Database`, not concrete classes)
 *   - `Dependency Injection` is used in the constructor of `UserService`
 */

#include <iostream>
using namespace std;

// Abstract interface for database (Abstraction Layer)
class Database {
public:
    virtual void save(string data) = 0;
};

// Low-level module: MySQL implementation
class MySQLDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

// Low-level module: MongoDB implementation
class MongoDBDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

// High-level module: depends only on abstraction (Database)
class UserService {
private:
    Database* db;  // Depends on abstraction

public:
    UserService(Database* database) {  
        db = database;
    }

    void storeUser(string user) {
        db->save(user);  // Doesn't care which DB is used
    }
};

int main() {
    MySQLDatabase mysql;
    MongoDBDatabase mongodb;

    UserService service1(&mysql);   // Inject MySQL implementation
    service1.storeUser("Aditya");

    UserService service2(&mongodb); // Inject MongoDB implementation
    service2.storeUser("Rohit");

    return 0;
}
