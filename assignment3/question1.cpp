#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructors
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    // Getter methods
    int getHour() {
        return hour;
    }

    int getMinute() {
        return minute;
    }

    int getSeconds() {
        return second;
    }

    // Setter methods
    void setHour(int h) {
        hour = h;
    }

    void setMinute(int m) {
        minute = m;
    }

    void setSeconds(int s) {
        second = s;
    }

    // Function to print time
    void printTime() {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    int numObjects;
    cout << "Enter the number of Time objects to create: ";
    cin >> numObjects;

    // Dynamically allocate memory for the array of Time objects
    Time *timeArray = new Time[numObjects];

    // Access and set values for each Time object
    for (int i = 0; i < numObjects; ++i) {
        int h, m, s;
        cout << "Enter hour for Time object " << i + 1 << ": ";
        cin >> h;
        cout << "Enter minute for Time object " << i + 1 << ": ";
        cin >> m;
        cout << "Enter second for Time object " << i + 1 << ": ";
        cin >> s;

        timeArray[i] = Time(h, m, s);
    }

    // Print values of each Time object
    cout << "\nValues of Time objects:" << endl;
    for (int i = 0; i < numObjects; ++i) {
        cout << "Time object " << i + 1 << ": ";
        timeArray[i].printTime();
    }

    // Free dynamically allocated memory
    delete[] timeArray;

    return 0;
}
