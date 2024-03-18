#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Base class representing a product
class Product {
protected:
    int id;
    string title;
    float price;

public:
    // Constructor
    Product(int i, const string& t, float p) : id(i), title(t), price(p) {}

    // Virtual function to calculate discounted price
    virtual float calculateDiscountedPrice() const = 0;

    // Function to display product details
    void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Price: $" << fixed << setprecision(2) << price << endl;
    }
};

// Derived class representing a book
class Book : public Product {
private:
    string author;

public:
    // Constructor
    Book(int i, const string& t, const string& a, float p) : Product(i, t, p), author(a) {}

    // Override to calculate discounted price for books (10% discount)
    float calculateDiscountedPrice() const override {
        return price * 0.9;
    }

    // Function to display book details
    void display() const {
        Product::display();
        cout << "Author: " << author << endl;
    }
};

// Derived class representing a tape
class Tape : public Product {
private:
    string artist;

public:
    // Constructor
    Tape(int i, const string& t, const string& ar, float p) : Product(i, t, p), artist(ar) {}

    // Override to calculate discounted price for tapes (5% discount)
    float calculateDiscountedPrice() const override {
        return price * 0.95;
    }

    // Function to display tape details
    void display() const {
        Product::display();
        cout << "Artist: " << artist << endl;
    }
};

int main() {
    vector<Product*> products; // Vector to store pointers to Product objects

    int choice;
    // Menu-driven loop to add products
    for (int i = 0; i < 3; ++i) {
        cout << "\nAdd Product " << i + 1 << ":" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add Tape" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id;
        string title;
        float price;
        switch (choice) {
            case 1:
                {
                    string author;
                    cout << "Enter book ID: ";
                    cin >> id;
                    cout << "Enter book title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter author: ";
                    getline(cin, author);
                    cout << "Enter price: ";
                    cin >> price;
                    products.push_back(new Book(id, title, author, price));
                }
                break;
            case 2:
                {
                    string artist;
                    cout << "Enter tape ID: ";
                    cin >> id;
                    cout << "Enter tape title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter artist: ";
                    getline(cin, artist);
                    cout << "Enter price: ";
                    cin >> price;
                    products.push_back(new Tape(id, title, artist, price));
                }
                break;
            default:
                cout << "Invalid choice. Please enter 1 or 2." << endl;
                --i; // Decrement i to redo current iteration
        }
    }

    // Calculate total bill
    float totalBill = 0.0;
    for (const auto& product : products) {
        totalBill += product->calculateDiscountedPrice();
    }

    // Display final bill
    cout << "\nFinal Bill: $" << fixed << setprecision(2) << totalBill << endl;

    // Free memory
    for (const auto& product : products) {
        delete product;
    }

    return 0;
}
