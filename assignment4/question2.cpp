#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Class representing a student
class Student {
private:
    string name;
    char gender;
    int rollNumber;
    float marks[3]; // Assuming 3 subjects

public:
    // Function to accept student details
    void accept() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks for 3 subjects:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    // Function to print student details
    void print() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Gender: " << gender << endl;
        float totalMarks = 0;
        for (int i = 0; i < 3; ++i) {
            totalMarks += marks[i];
        }
        float percentage = (totalMarks / 3.0);
        cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
    }

    // Function to get roll number
    int getRollNumber() {
        return rollNumber;
    }

    // Function to compare two students based on roll number
    bool operator<(const Student &other) const {
        return rollNumber < other.rollNumber;
    }
};

// Function to sort student records based on roll number
void sortRecords(Student arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to search for a student by roll number
int searchRecords(Student arr[], int size, int rollNumber) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].getRollNumber() == rollNumber) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    const int maxSize = 100;
    Student students[maxSize];
    int numStudents = 0;

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Accept Student Records" << endl;
        cout << "2. Print Student Records" << endl;
        cout << "3. Search Student Records" << endl;
        cout << "4. Sort Student Records" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (numStudents < maxSize) {
                    cout << "Enter details for Student " << numStudents + 1 << ":" << endl;
                    students[numStudents++].accept();
                } else {
                    cout << "Maximum limit reached." << endl;
                }
                break;

            case 2:
                if (numStudents > 0) {
                    for (int i = 0; i < numStudents; ++i) {
                        cout << "\nDetails for Student " << i + 1 << ":" << endl;
                        students[i].print();
                    }
                } else {
                    cout << "No records available." << endl;
                }
                break;

            case 3:
                int roll;
                cout << "Enter the roll number to search: ";
                cin >> roll;
                {
                    int index = searchRecords(students, numStudents, roll);
                    if (index != -1) {
                        cout << "Student found at index " << index + 1 << endl;
                        cout << "Details:" << endl;
                        students[index].print();
                    } else {
                        cout << "Student not found." << endl;
                    }
                }
                break;

            case 4:
                if (numStudents > 0) {
                    sortRecords(students, numStudents);
                    cout << "Records sorted successfully." << endl;
                } else {
                    cout << "No records available to sort." << endl;
                }
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
