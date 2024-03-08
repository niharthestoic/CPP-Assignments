#include<stdio.h>
struct Date
{
    int day;
    int month;
    int year;

};
void initDate (struct Date *ptrDate)
{
    ptrDate->day = 0;
    ptrDate->month = 0;
    ptrDate->year = 0;

}
void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date- %d /%d /%d \n", ptrDate->day,ptrDate->month,ptrDate->year);

}
void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("enter date in dd mm yyyy format-");
    scanf("%d%d%d", &ptrDate->day,&ptrDate->month,&ptrDate->year);

}
int main()
{
    struct Date D1;
    int choice;
    
    do
    {
        printf("\n1. Intialize date");
        printf("\n2. print date");
        printf("\n3. accept date");
        printf("\n4. exit");
        printf(" enter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
            initDate(&D1);
            printf("date initialized.\n");
            break;
            case 2: 
            printDateOnConsole(&D1);
            break;
            case 3: 
            acceptDateFromConsole(&D1);
            break;
            case 4: 
            printf("EXIT\n");
            
            break;
            default: 
            printf("invalid choice.enter between 1 and 4\n");
        }

        } while(choice != 4);
    return 0;
    
}
