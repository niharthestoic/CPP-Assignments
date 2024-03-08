#include<iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
void initDate()
{
    day=0;
    month=0;
    year=0;
}
void printDateOnConsole()
{
    cout<<"Date:"<<day<<"/"<<month<<"/"<<year<<endl;
}
void acceptDateFromConsole()
{
    cout<<"enter date in dd mm  yyyy format";
    cin>>day>>month>>year;
}
bool isLeapyear()
{
    return ((year%4==0 && year%100 !=0)|| (year%400==0));
}
};
int main()
{
    Date D1;
    int choice;
    do
    {
        cout<<"\n Menu\n";
        cout<<"1. initialize date\n";
        cout<<"2. print date\n";
        cout<<"3. Accept date\n";
        cout<<"4.check leap year\n";
        cout<<"5. EXIT\n";
        cout<<"enter your choice";
        cin>>choice;
        switch (choice)
        {
            case 1:
            D1.initDate();
            break;
            case 2:
            D1.printDateOnConsole();
            break;
            case 3:
            D1.acceptDateFromConsole();
            break;
            case 4:
            if(D1.isLeapyear())
            cout<<" leap year\n";
            else
            cout<<" not a leap year\n";
            break;
            default :
            cout<<"invalid choice. enter choice between 1 to 4";
            
}
    } while (choice !=5);
    return 0;

}
