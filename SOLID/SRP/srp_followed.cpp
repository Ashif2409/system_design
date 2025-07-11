// S: Single Responsibility Principle (SRP)
// Every class should do only one thing — have one job.
// This makes the code easier to understand, change, and reuse.
//
// In this code:
// - Product class only stores product data
// - ShoppingCart only manages products
// - CartInvoicePrinter only prints invoices
// - ShoppingCartStorage only handles saving cart

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

class ShoppingCartStorage {
private:
    ShoppingCart* cart;
public:
    ShoppingCartStorage(ShoppingCart* cart) {
        this->cart = cart;
    }

    void saveCart() const {
        cout << "Saving cart with total price: " << cart->totalPrice() << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    CartInvoicePrinter* printer = new CartInvoicePrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveCart();

    return 0;
}
