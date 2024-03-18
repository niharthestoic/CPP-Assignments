#include <iostream>
using namespace std;

class Employee
{
private:
    int empid;
    double salary;

public:
    Employee()
    {
        cout << "Employee Parmeterless Ctor" << endl;
        empid = 0;
        salary = 0;
    }
    Employee(int empid, double salary)
    {
        cout << "Employee Parmeterized Ctor" << endl;
        this->empid = empid;
        this->salary = salary;
    }
    void setEmpId(int empid)
    {
        this->empid = empid;
    }
    virtual void accept()
    {
        cout << "Enter empid - ";
        cin >> empid;
        cout << "Enter salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Empid - " << empid << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "Employee Destructor" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter bonus - ";
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        //cout << "Manager Parameterless Ctor - " << endl;
        bonus = 0;
    }
    Manager(int empid, double salary, double bonus) : Employee(empid, salary)
    {
        //cout << "Manager Parameterized Ctor - " << endl;
        this->bonus = bonus;
        // this->setEmpId(empid); // way 2
    }

    void accept()
    {
        Employee::accept(); // id,sal
        acceptManager();    // bonus
    }
    void display()
    {
        Employee::display();
        this->displayManager();
    }

    ~Manager()
    {
        cout << "Manager Destructor" << endl;
    }
};

class SalesMan : virtual public Employee
{
private:
    double comm;

protected:
    void acceptSalesman()
    {
        cout << "Enter Commission - ";
        cin >> comm;
    }

    void displaySalesman()
    {
        cout << "Commission - " << comm << endl;
    }

public:
    SalesMan()
    {
        //cout << "Salesman Parameterless Ctor - " << endl;
        comm = 0;
    }
    SalesMan(int empid, double salary, double comm) : Employee(empid, salary)
    {
       // cout << "SalesMan Parameterized Ctor - " << endl;
        this->comm = comm;
    }

    void accept()
    {
        Employee::accept(); // id , sal
        acceptSalesman();   // comm
    }
    void display()
    {
        Employee::display();
        this->displaySalesman();
    }

    ~SalesMan()
    {
        //cout << "SalesMan Destructor" << endl;
    }
};

class SalesManager : public Manager, public SalesMan
{
public:
    SalesManager()
    {
        
    }

    SalesManager(int empid, double salary, double bonus, double comm)
    {
        this->setEmpId(empid);
        // todo
    }
    void accept()
    {
        Employee::accept(); // id,sal
        acceptManager();    // bonus
        acceptSalesman();   // comm
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
    ~SalesManager()
    {
        cout << "SalesManager Destructor" << endl;
    }
};

int menu()
{
    int choice;
    cout << "0. EXIT" << endl;
    cout<<"  1. Accept Employee as a Manager"<<endl;
    cout<<"  2. Accept Employee as a SalesMan"<<endl;
    cout<<"  3. Accept Employee as a SalesManager"<<endl;
    cout << "4. Display All managers" << endl;
    cout << "5. Display All Salesman" << endl;
    cout << "6. Display All SalesManagers" << endl;
    cout << "7. Display  Count of All employees with Designation " << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    return choice;
}

int main()
{
    int size ,choice , count=0 ,man=0 ,salesman =0 , salesmanager=0;
    cout << "Enter the size for the array - ";
    cin >> size;
    Employee *employee[size];

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (count < size)
            {
                employee[count] = new Manager(); // upcasting
                employee[count]->accept();    //
                man++;
                count++;
            }
            else
                cout << "Array is full" << endl;
            break;
        case 2:
            if (count < size)
            {
                employee[count] = new SalesMan(); // upcasting
                employee[count]->accept();    //
                salesman++;
                count++;
            }
            else
                cout << "Array is full" << endl;
            break;   

        case 3:
            if (count < size)
            {
                employee[count] = new SalesManager(); // upcasting
                employee[count]->accept();    //
                salesmanager++;
                count++;
            }
            else
                cout << "Array is full" << endl;
            break;   
   
        case 4:
            if(man > 0){
                                for (int i = 0; i < count; i++){
                                    if (typeid(*employee[i]) == typeid(Manager)){
                                        employee[i]->display();
                                   }
                                }
                            // else if(typeid(*employee[i]) !=  typeid(Manager)){
                            //     cout<<"There are no managers"<<endl;
                            // }
                        }
            else{
                cout<<"There are no managers"<<endl;
            }
            
            break;
        case 5:
            if(salesman>0){
                        for (int i = 0; i < count; i++){
                            if (typeid(*employee[i]) == typeid(SalesMan)){
                                employee[i]->display();
                            }
                        }

            }
            
            else{
                    cout<<"There are no salesman"<<endl;
                }
            break;
        case 6:
            if(salesmanager>0) {
                    for (int i = 0; i < count; i++){
                        if (typeid(*employee[i]) == typeid(SalesManager)){
                            employee[i]->display();
                        }
                    }
                }
                
                
            else{
                    cout<<"There are no salesmanager"<<endl;
                }
            break;
        
        case 7 :
                cout<<"There are "<<man<<"  - "<<"Manager"<<endl;
                cout<<"There are "<<salesman<<"  - "<<"SalesMan"<<endl;
                cout<<"There are "<<salesmanager<<"  - "<<"SalesManager"<<endl;
            break;
        default:
            cout << "Wrong choice ..." << endl;
            break;
        }
    }


        for (int i = 0; i < count; i++)
        delete employee[i];
    

    

    return 0;
}