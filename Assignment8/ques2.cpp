#include<iostream>
using namespace std;

enum class Account_type{
            Saving =1,
            Current,
            DMAT
        };


class insufficient_funds{

    private:
    string message;

    public:
        insufficient_funds(){
            message = "You dont have sufficient amount to withdraw";
        }

        insufficient_funds(string message){
            this->message =message;

        }

        void display(){
            cout<<message<<endl;
        }


};

class Account{
    private:
    int id;
    double balance;
    Account_type account_type; 

    public:
        
        Account(){
            id=this->id;
            balance = this->balance;
            account_type = this->account_type;
        }
        

    void setID(){
        id = this->id;
    }    
    void setBalance(){
        balance =this->balance;
    }


    Account_type getType(){
        return account_type ;
    }
    int getID(){
        return this->id;
    }
    int getBalance(){
        return this->balance;
    }    

    void accept(){
        cout<<"Enter Account ID"<<endl;
        cin>>id;
        cout<<"Enter Initial Balance"<<endl;
        cin>>balance;
        int type;
        cout<<"Choose Account type ( 1: Saving , 2: Current , 3: Dmat)"<<endl;
        cin>>type;

        switch (type){
            case 1:
            account_type  =  Account_type ::Saving;
                break;
            
            case 2:
            account_type  =  Account_type ::Current;
                break;
            
            case 3:
            account_type  =  Account_type ::DMAT;
                break;
            
            default:
            cout<<"Invalid Type chosen . Default type Savings is selected"<<endl;
                        account_type  =  Account_type ::Saving;
                        break;       
        }
    }

    void display(){
        cout<<"The Account id is "<<id<<endl;
        cout<<"The Account Balance  is "<<balance<<endl;
        cout<<"The account type is ";
        switch (account_type) {
            case Account_type::Saving:
                cout << "Saving";
                break;
            case Account_type::Current:
                cout << "Current";
                break;
            case Account_type::DMAT:
                cout << "DMAT";
                break;
        }cout << endl;
        
        
    }

    void deposit(double amount){
        if(amount>0){
            
            this->balance = this->balance + amount;
        }
        else{
            throw insufficient_funds("please provide a valid amount to be deposit");
        }
        
    }

    void withdraw(double amount){
        if(amount <= balance){
            this->balance = this->balance - amount;
        }
        else{
            throw insufficient_funds();
        }

         
    }



};




int main(){
    cout<<"Enter the account for 3 persons"<<endl;
    Account *obj[3] ;
    int choice;
    int index =0;
    int i=0;
    double amt =0;
    

    try{
            do{
                cout<<"0.Exit"<<endl;
                cout<<"1.Add Acount"<<endl;
                cout<<"2.Deposit money"<<endl;
                cout<<"3.withdraw Money"<<endl;

                cin>>choice;
                switch(choice){
                    case 0 :
                            cout<<"Thankyou Visit gain"<<endl;
                            break;

                    case 1:
                        for(int i=0 ; i<3;i++){
                            obj[i] = new Account();
                            obj[i]->accept();

                        }
                        
                        break;

                    case 2:
                        cout<<"Please Select the account "<<endl;
                        for(i =0 ;i<3;i++){
                            
                            cout<<"press - "<<i<<" To deposit in Account having ID - "<<obj[i]->getID()<<endl;
                        }
                        cin>>index;
                        if(index>i){
                            throw insufficient_funds("please select a Valid account");
                        }
                        else{
                            cout<<"The Balance is "<<obj[index]->getBalance()<<endl;
                            cout<<"Enter the amount to be deposited "<<endl;
                            cin>>amt;
                            obj[index]->deposit(amt);
                            cout<<"The Updated Balance is "<<obj[index]->getBalance()<<endl;
                            index =0;
                            amt=0;
                        }
                        
                    break;
                    
                    case 3:
                        cout<<"Please Select the account "<<endl;
                        for(int i=0;i<3;i++){
                            
                            cout<<"press - "<<i<<" To Withdraw from Account having ID - "<<obj[i]->getID()<<endl;
                            
                        }
                        cin>>index;
                        if(index>i){
                            throw insufficient_funds("please select a Valid account");
                        }
                        else{
                            cout<<"The Balance is "<<obj[index]->getBalance()<<endl;
                            cout<<"Enter the amount to  Withdraw "<<endl;
                            cin>>amt;
                            obj[index]->withdraw(amt);
                            cout<<"The Updated Balance is "<<obj[index]->getBalance()<<endl;
                            index =0;
                            amt=0;
                        }
                        
                    break;

                }


            } while(choice!=0);
        }
    
    catch(insufficient_funds &error){
        error.display();

    }
}