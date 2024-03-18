#include <iostream>

using namespace std;

class Box {
private:
    float length;
    float width;
    float height;

public:
    // Constructor
    Box(float l, float w, float h) {
        length = l;
        width = w;
        height = h;
    }

    // Method to calculate volume
    float calculateVolume() {
        return length * width * height;
    }
};

int main() {
    float length, width, height;
    int choice;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Calculate Volume" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the length of the box: ";
                cin >> length;
                cout << "Enter the width of the box: ";
                cin >> width;
                cout << "Enter the height of the box: ";
                cin >> height;

                // Create Box object
                Box box(length, width, height);
                cout << "Volume of the box: " << box.calculateVolume() << endl;
                break;

            case 2:
                cout << "Exiting..." << endl;
                break;


            default:
                cout << "Invalid choice. Please enter 1 or 2." << endl;
                break;
        }
    }

    return 0;
}
