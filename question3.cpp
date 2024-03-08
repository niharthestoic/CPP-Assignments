#include<iostream>
using namespace std;
class Student
{
private:
    int rollno;
    string name;
    int marks;

public:
void initStudent()
{
    rollno=100;
    name="nihar";
    marks=100;
}
void acceptDateFromConsole()
{
    cout<<"Roll no-";
    cin>>rollno;
    cout<<"enter name-";
    cin>>name;
    cout<<"enter marks(max marks=100)-";
    cin>>marks;
}
void printStudentOnConsole()
{
    cout<<"Roll no-"<<rollno<<endl;
    cout<<"enter name-"<<name<<endl;
    cout<<"marks"<<marks<<endl;
    
}

};
int main()
{
    Student S1;
    int choice;
    do
    {
        cout<<"\n Menu\n";
        cout<<"1. initialize student info \n";
        cout<<"2. print student info\n";
        cout<<"3. Accept student info\n";
        cout<<"4. EXIT\n";
        cout<<"enter your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1:
            S1.initStudent();
            break;
            case 2:
            S1.printStudentOnConsole();
            break;
            case 3:
            S1.acceptDateFromConsole();
            break;
            
            default :
            cout<<"invalid choice. enter choice between 1 to 3";
            
}
    } while (choice !=4);
    return 0;

}
