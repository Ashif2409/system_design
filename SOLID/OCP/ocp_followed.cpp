// O: Open/Closed Principle (OCP)
// Code should be open for extension but closed for modification.
// This means you should be able to add new features without changing existing code.
//
// In this code:
// - The `PersistentStorage` class is an interface.
// - New storage types (SQL, MongoDB, File) are added by extending the base class.
// - We don’t change `ShoppingCart` or `CartInvoicePrinter` to support new storage systems.

#include <bits/stdc++.h>
using namespace std;

class Product {
private:
    string name;
    int price;
public:
    Product(string name, int prices) {
        this->name = name;
        this->price = prices;
    }

    string getName() const {
        return name;
    }

    int getPrice() const {
        return price;
    }

    ~Product() {
    }
};

class ShoppingCart {
private:
    vector<Product*> products;
public:
    void addProduct(Product* product) {
        products.push_back(product);
    }

    vector<Product*> getProducts() const {
        return products;
    }

    int totalPrice() const {
        int total = 0;
        for (auto product : products) {
            total += product->getPrice();
        }
        return total;
    }
};

class CartInvoicePrinter {
private:
    ShoppingCart* cart;
public:
    CartInvoicePrinter(ShoppingCart* cart) {
        this->cart = cart;
    }

    void printInvoice() const {
        cout << "Invoice: " << endl;
        for (auto product : cart->getProducts()) {
            cout << "Product: " << product->getName()
                 << ", Price: " << product->getPrice() << endl;
        }
    }
};

class PersistentStorage {
public:
    virtual void save(const ShoppingCart* cart) const = 0;
};

class SQLStorage : public PersistentStorage {
public:
    void save(const ShoppingCart* cart) const override {
        cout << "Saving cart to SQL database with total price: " << cart->totalPrice() << endl;
    }
};

class MongoDBStorage : public PersistentStorage {
public:
    void save(const ShoppingCart* cart) const override {
        cout << "Saving cart to MongoDB with total price: " << cart->totalPrice() << endl;
    }
};

class FileStorage : public PersistentStorage {
public:
    void save(const ShoppingCart* cart) const override {
        cout << "Saving cart to file with total price: " << cart->totalPrice() << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    CartInvoicePrinter* printer = new CartInvoicePrinter(cart);
    printer->printInvoice();

    PersistentStorage* sql = new SQLStorage();
    PersistentStorage* mongo = new MongoDBStorage();
    PersistentStorage* file = new FileStorage();

    sql->save(cart);
    mongo->save(cart);
    file->save(cart);

    return 0;
}
