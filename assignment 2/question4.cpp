#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string building;
    string street;
    string city;
    int pin;

public:
    // Constructors
    Address() {
        building = "";
        street = "";
        city = "";
        pin = 0;
    }

    Address(string building, string street, string city, int pin) {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    // Getter methods
    string getBuilding() {
        return building;
    }

    string getStreet() {
        return street;
    }

    string getCity() {
        return city;
    }

    int getPin() {
        return pin;
    }

    // Setter methods
    void setBuilding(string building) {
        this->building = building;
    }

    void setStreet(string street) {
        this->street = street;
    }

    void setCity(string city) {
        this->city = city;
    }

    void setPin(int pin) {
        this->pin = pin;
    }

    // Accept method
    void accept() {
        cout << "Enter building: ";
        cin.ignore();
        getline(cin, building);
        cout << "Enter street: ";
        getline(cin, street);
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter pin: ";
        cin >> pin;
    }

    // Display method
    void display() {
        cout << "Building: " << building << endl;
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Pin: " << pin << endl;
    }
};

int main() {
    Address addr1; // Using default constructor
    Address addr2("ABC Towers", "Main Street", "New York", 12345); // Using parameterized constructor

    cout << "Enter details for Address 1:" << endl;
    addr1.accept(); // Accept details for Address 1

    cout << "\nAddress 1 Details:" << endl;
    addr1.display(); // Display details for Address 1

    cout << "\nAddress 2 Details:" << endl;
    addr2.display(); // Display details for Address 2

    return 0;
}
