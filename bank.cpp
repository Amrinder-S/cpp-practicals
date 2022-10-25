#define PENELTY_AMOUNT 500 //Penelty Amount, can be changed from here if required.
#define MINIMUM_BALANCE 10000
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class account {
    string customer_name;
    int account_number;
    float balance=0;
    public:
    static int account_number_count; //this is to keep track of account number, so no same account with two different account numbers is made.
    void accountCreate(string);

    void deposit()
    {
        int newBalance=0;
        cout<<"\nEnter the amount to deposit: ";
        cin>>newBalance;
        if(newBalance<0) newBalance=-newBalance; //if a negative value is supplied, convert it to positive
        cout<<"Amount "<<newBalance<<" deposited to bank account #"<<account_number<<endl;
        cout<<"Old balance: "<<balance;
        balance+=newBalance;    
        cout<<" | New balance: "<<balance<<endl;
    }

    void withdraw()
    {
        int newBalance=0;
        cout<<"\nEnter the amount to withdraw: ";
        cin>>newBalance;
        if(newBalance<0) newBalance=-newBalance; //if a negative value is supplied, convert it to positive
        cout<<"Amount "<<newBalance<<" withdrawn from bank account #"<<account_number<<endl;
        cout<<"Old balance: "<<balance;
        balance-=newBalance;    
        cout<<" | New balance: "<<balance<<endl;
    }
    void displayBalance()
    {
        cout<<"\nBalance for Account #"<<account_number<<" : "<<balance<<"\nCustomer Name: "<<customer_name<<endl;
    }

    void alterBalance(float newBalance=0) //function to change balance, in case of penelty or compound interest
    {
        balance+=newBalance;
    }

    float returnBalance()
    {
        return balance;
    }

};
int account::account_number_count;

void account::accountCreate(string account_type)
{
        {
        cout<<"\nEnter customer Name: ";
        getline(cin >> ws, customer_name, '\n');
        account_number = account::account_number_count;
        cout<<"Account number "<<account::account_number_count<<" Created.\nCustomer Name: "<<customer_name<<"\nBalance: "<<balance<<"\nAccount Type: "<<account_type<<" account."<<endl;
        account::account_number_count++;
    }
}

class cur_acct: public account {
public:
//check book facility coming soon
cur_acct() { accountCreate("Current");}
void applyPenelty()
{
    if(returnBalance()<MINIMUM_BALANCE)
        {
            cout<<"\nService charge of "<<PENELTY_AMOUNT<<" applied.";
            cout<<"\nOld Balance: "<<returnBalance();
            alterBalance(-PENELTY_AMOUNT);
            cout<<" | New Balance: "<<returnBalance()<<endl;
        }
}
void chequeBookFacility()
{
    cout<<"\nCheque book facility is available. Please apply at local branch.\n";
}

};

class sav_acct: public account {
public:
//Compound Interest coming soon
    sav_acct() { accountCreate("Savings");}
    
    void compoundInterest()
    {
    float principal = returnBalance(),rate=5,time=1,ci;

    ci = principal*pow((1+rate/100),time);

    cout<<"\nCompound interest of "<<ci<<" deposited into your account."<<endl;
    cout<<"Old balance: "<<returnBalance();
    alterBalance(ci - returnBalance());
    cout<<" | New balance: "<<returnBalance()<<endl;
    }
};

int main()
{
    cur_acct a;
    a.deposit();
    a.withdraw();
    a.displayBalance();
    a.applyPenelty();
    a.chequeBookFacility();

    sav_acct b;
    b.deposit();
    b.withdraw();
    b.displayBalance();
    b.compoundInterest();
}