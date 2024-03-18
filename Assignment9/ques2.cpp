#include <iostream>
#include <vector>
using namespace std;
enum account_type
{
    SAVING,
    CURRENT,
    DMAT
};

class inSuffientFunds
{
private:
    int accid;
    double cur_balance;
    double withdraw_amount;

public:
    inSuffientFunds(int id, double curBalance, double withdrawAmount)
    {
        this->accid = id;
        this->cur_balance = curBalance;
        this->withdraw_amount = withdrawAmount;
    }
    void display()
    {
        cout << "------Transaction Failed--------" << endl;
        cout << "Account ID:" << accid << "\nCurrent Balance:" << cur_balance << "\nAttempt to Withdraw Amount:" << withdraw_amount << endl;
    }
};

class Account
{
private:
    int id;
    account_type type;
    double balance;

public:
    Account() : Account(0, SAVING, 0.00) {}
    Account(int id, account_type type, double balance)
    {
        this->id = id;
        this->type = type;
        this->balance = balance;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_type(account_type type)
    {
        this->type = type;
    }
    void set_balance(double balance)
    {
        this->balance = balance;
    }
    int get_id()
    {
        return this->id;
    }
    account_type get_type()
    {
        return this->type;
    }
    double get_balance()
    {
        return this->balance;
    }
    void accept()
    {
        int type;
        cout << "Enter Account Details::" << endl;
        cout << "Enter Account ID:";
        cin >> this->id;
        do
        {
            cout << "Choose Account type" << endl;
            cout << "Press 0.For SAVINGS Account" << endl;
            cout << "Press 1.For Current Account" << endl;
            cout << "Press 2.For DMAT Account" << endl;
            cout << "Enter Choice:";
            cin >> type;
            if (type != 0 && type != 1 && type != 2)
                cout << "Invalid Choice has been entered" << endl;
        } while (type != 0 && type != 1 && type != 2);
        this->type = (account_type)type;
        cout << "Enter Initial Balance:";
        cin >> this->balance;
    }
    void display()
    {
        cout << "\nAccount Details::" << endl;
        cout << "Account ID:" << id << endl;
        if (type == 0)
            cout << "Account Type:Saving Account" << endl;
        else if (type == 1)
            cout << "Account Type:Current Account" << endl;
        else if (type == 2)
            cout << "Account Type:DMAT Account" << endl;
        cout << "Account Balance:" << balance << endl;
    }
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw inSuffientFunds(this->id, this->balance, amount);
        }
        else
        {
            set_balance(this->balance - amount);
        }
    }
    void deposit(double amount)
    {

        set_balance(this->balance + amount);
    }
};

int main1()
{
    class Account a1;
    double amt;
    a1.accept();
    a1.display();
    cout << endl;
    cout << "Enter Amount to Withdraw:";
    cin >> amt;
    try
    {
        a1.withdraw(amt);
    }
    catch (inSuffientFunds e)
    {
        e.display();
    }
    a1.display();
    cout << endl;
    cout << "Enter Amount to Deposit:";
    cin >> amt;
    a1.deposit(amt);
    cout << endl;
    a1.display();
    return 0;
}

int menu()
{
    int ch;
    cout << "\n::Program Menu::" << endl;
    cout << "0.To Exit" << endl;
    cout << "1.To Add Account" << endl;
    cout << "2.To Display All Account" << endl;
    cout << "3.To Deposit to Account" << endl;
    cout << "4.To Withdraw from Account" << endl;
    cout << "Enter Choice:";
    cin >> ch;
    return ch;
}
int main()
{
    int ch;
    int id;
    double amt;
    bool flag = false;
    vector<Account *> accounts;
    Account *aptr = NULL;
    int iden = 0;
    while ((ch = menu()) != 0)
    {
        switch (ch)
        {
        case 1:
            aptr = new Account;
            aptr->accept();
            accounts.push_back(aptr);
            break;
        case 2:
            if (accounts.size() == 0)
                cout << "No Accounts are Present in System" << endl;
            else
            {
                for (int i = 0; i < accounts.size(); i++)
                    aptr->display();
            }
            break;
        case 3:
            if (accounts.size() == 0)
                cout << "No Accounts are Present in System" << endl;
            else
            {
                cout << "Enter Account ID:";
                cin >> id;
                for (int i = 0; i < accounts.size(); i++)
                {
                    if (accounts[i]->get_id() == id)
                    {
                        flag = true;
                        cout << "Enter Amount to Deposit:";
                        cin >> amt;
                        accounts[i]->deposit(amt);
                    }
                }
                if (flag == false)
                    cout << "No Account with ID" << id << " is Found";
            }
            break;
        case 4:
            if (accounts.size() == 0)
                cout << "No Accounts are Present in System" << endl;
            else
            {
                cout << "Enter Account ID:";
                cin >> id;
                for (int i = 0; i < accounts.size(); i++)
                {
                    if (accounts[i]->get_id() == id)
                    {
                        flag = true;
                        cout << "Enter Amount to Withdraw:";
                        cin >> amt;
                        try
                        {
                            accounts[i]->withdraw(amt);
                        }
                        catch (inSuffientFunds &e)
                        {
                            e.display();
                        }
                    }
                }
                if (flag == false)
                    cout << "No Account with ID:" << id << " is Found";
            }
            break;
        default:
            cout << "Invalid Input Given" << endl;
            break;
        }
        flag = false;
    }
    cout << "Thanks for Using" << endl;
    for (int i = 0; i < accounts.size(); i++)
        delete accounts[i];
    aptr = NULL;
    return 0;
}
