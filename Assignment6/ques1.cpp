#include<iostream>
using namespace std;

class Employee{
    private:
        int id;
        float sal;

    public:
    Employee(){
        id =0;
        sal = 0.0;

    }

    Employee(int id , float sal){
        id = this->id;
        sal = this->sal;

    }

    int getID(){
        return this->id;
    }

    int getSAL(){
        return this->sal;
    }
    void setID(){
        id= this->id;
    }
    void setSAL(){
        sal = this->sal;
    }

    virtual void accept(){
        cout<<"Enter Employee ID"<<endl;
        cin>>id;
        cout<<"Enter Employee Salary"<<endl;
        cin>>sal;

    }

     virtual void display(){
        cout<<"Employee ID  = "<<id<<endl;
        cout<<"Employee Salary = "<<sal<<endl;
    }
};

class Manager  : public Employee{
    private:
        float bonus;
    
    public:

    Manager(){
        bonus=0.0;
    }

    Manager(int id , float sal, float bonus){
        id = this->getID();
        sal = this->getSAL();
        bonus = this->bonus;
    }

    int getBonus(){
        return this->bonus;
    }
    void setBonus(){
        bonus = this->bonus;
    }

     virtual void accept(){
        Employee::accept();
        cout<<"Enter the Bonus for Manager"<<endl;
        cin>>bonus;
    }

    virtual void display(){
        Employee::display();
        cout<< "Bonus for Manager = "<<bonus<<endl;
    }

    void accept_manager(){
        this->accept();
    }

     void display_manager(){
        this->display();
    }

};

class SalesMan : public Employee{
    private:
        float comm;
    
    public:
       SalesMan(){
        comm =0.0;
       }

       SalesMan(int id , float sal , float comm){
        id  = this->getID();
        sal = this->getSAL();
        comm  = this->comm;
       }

    int getComm(){
        return this->comm;
    }
    void setComm(){
        comm = this->comm;
    }

    virtual void accept(){
        Employee::accept();
        cout<<"Enter the Commission for Salesman"<<endl;
        cin>>comm;
    }

    virtual void display(){
        Employee::display();
        cout<< "Commission for Salesman = "<<comm<<endl;
    }

    void accept_salesman(){
        this->accept();
    }

    void display_salesman(){
        this->display();
    }



};

class Sales_Manager: public Manager , public SalesMan{
    public:
        Sales_Manager(){

        }
        Sales_Manager(int id , float sal , float bonus , float comm){
        
        }
            




    void accept(){
        if(typeid(this).name() == typeid(SalesMan).name()){
            this->accept_salesman();
        }
        if(typeid(this).name() == typeid(Manager).name()){
            this->accept_manager();
        }
        
    }

    void display(){
        if(typeid(this).name() == typeid(SalesMan).name()){
            this->display_salesman();
        }
        if(typeid(this).name() == typeid(Manager).name()){
            this->display_manager();
        }
        
        
    }

};


int main(){
    int size;
    cout<<"Enter the no. of employees "<<endl;
    cin>>size;
    Employee e1;
    Manager m1;
    SalesMan sm1;

    Employee *employee[size]; 

    employee[0] = new Manager();
    employee[0]->accept();
    employee[0]->display();

    employee[1] = new SalesMan();
    employee[1]->accept();
    employee[1]->display();


    // m1.accept();
    // m1.display();
    // sm1.accept();
    // sm1.display();

    




}