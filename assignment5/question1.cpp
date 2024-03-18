#include <iostream>
#include <string>
using namespace std;

// Class representing a date
class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructors
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Getter methods
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setter methods
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    // Function to display date
    void display() const {
        cout << day << "/" << month << "/" << year;
    }
};

// Class representing a person
class Person {
protected:
    string name;
    string address;
    Date birthDate;

public:
    // Constructors
    Person() {}
    Person(const string &n, const string &a, const Date &bd) : name(n), address(a), birthDate(bd) {}

    // Getter methods
    string getName() const { return name; }
    string getAddress() const { return address; }
    Date getBirthDate() const { return birthDate; }

    // Setter methods
    void setName(const string &n) { name = n; }
    void setAddress(const string &a) { address = a; }
    void setBirthDate(const Date &bd) { birthDate = bd; }

    // Function to display person details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birth Date: ";
        birthDate.display();
        cout << endl;
    }
};

// Class representing an employee, inheriting from Person
class Employee : public Person {
private:
    int id;
    float salary;
    string department;
    Date joiningDate;

public:
    // Constructors
    Employee() {}
    Employee(const string &n, const string &a, const Date &bd, int i, float s, const string &d, const Date &jd)
        : Person(n, a, bd), id(i), salary(s), department(d), joiningDate(jd) {}

    // Getter methods
    int getId() const { return id; }
    float getSalary() const { return salary; }
    string getDepartment() const { return department; }
    Date getJoiningDate() const { return joiningDate; }

    // Setter methods
    void setId(int i) { id = i; }
    void setSalary(float s) { salary = s; }
    void setDepartment(const string &d) { department = d; }
    void setJoiningDate(const Date &jd) { joiningDate = jd; }

    // Function to display employee details
    void display() const {
        Person::display();
        cout << "Employee ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
        cout << "Joining Date: ";
        joiningDate.display();
        cout << endl;
    }
};

int main() {
    // Test the classes
    Date birthDate1(25, 3, 1990);
    Date joiningDate1(10, 6, 2015);
    Employee emp1("John Doe", "123 Main St", birthDate1, 1001, 50000.0, "IT", joiningDate1);

    Date birthDate2(15, 7, 1985);
    Date joiningDate2(5, 8, 2010);
    Employee emp2;
    emp2.setName("Jane Smith");
    emp2.setAddress("456 Oak St");
    emp2.setBirthDate(birthDate2);
    emp2.setId(1002);
    emp2.setSalary(60000.0);
    emp2.setDepartment("HR");
    emp2.setJoiningDate(joiningDate2);

    // Display employee details
    cout << "Employee 1 Details:" << endl;
    emp1.display();

    cout << "Employee 2 Details:" << endl;
    emp2.display();

    return 0;
}
