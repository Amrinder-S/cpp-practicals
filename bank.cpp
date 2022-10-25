#define PENELTY_AMOUNT 500 //Penelty Amount, can be changed from here if required.
#define WITHDRAW 0 
#define DEPOSIT 1
#define APPLY_PENELTY 2
#include<iostream>
#include<string>
using namespace std;

class account {
    string customer_name;
    int account_number;
    float balance=0;
    public:
    static int account_number_count; //this is to keep track of account number, so no same account with two different account numbers is made.
    void accountCreate(string);
    void alterBalance(int argument) // this function is made to do withdraw, deposit and applying penelty if required.
    {
        int newBal = 0;
        if(argument==APPLY_PENELTY) //if an argument (2) is supplied, apply penelty
        {
            cout<<"\nService charge of "<<PENELTY_AMOUNT<<" applied to account #"<<account_number<<endl;
            cout<<"Old balance: "<<balance;
            balance-=PENELTY_AMOUNT;
            cout<<" | New balance: "<<balance<<endl;
        }
        else if (argument==WITHDRAW||argument==DEPOSIT) // if withdraw or deposit argument is passed, do the desired operation.
        {

        cout<<"\nEnter the amount to "<<(argument?"deposit":"withdraw")<<": ";
        cin>>newBal;
        if(newBal<0) newBal=-newBal; //if a negative value is supplied, convert it to positive
        cout<<"Amount "<<newBal<<(argument?" deposited to":" withdrawn from")<<" bank account #"<<account_number<<endl;
        cout<<"Old balance: "<<balance;
        argument? balance+=newBal : balance-=newBal; //Use of conditional operator to alter balance based on argument.
        cout<<" | New balance: "<<balance<<endl;
        }
    }
    void showBalance()
    {
        cout<<"\nBalance for Account #"<<account_number<<" : "<<balance<<"\nCustomer Name:"<<customer_name<<endl;
    }

};
int account::account_number_count;

void account::accountCreate(string account_type)
{
        {
        cout<<"\nEnter customer Name:";
        getline(cin >> ws, customer_name, '\n');
        account_number = account::account_number_count;
        cout<<"Account number "<<account::account_number_count<<" Created.\nCustomer Name: "<<customer_name<<"\nBalance: "<<balance<<"\nAccount Type: "<<account_type<<endl;
        account::account_number_count++;
    }
}

class cur_acct: public account {
public:
//check book facility coming soon
void checkPenelty() {alterBalance(APPLY_PENELTY);}
void withdraw() {alterBalance(WITHDRAW); }
void deposit() {alterBalance(DEPOSIT);}
void createAccount() { accountCreate("Current");}
void showBal() {cout<<balance;}
};

class sav_acct: public account {
public:
//Compound Interest coming soon
void withdraw() {alterBalance(WITHDRAW); }
void deposit() {alterBalance(DEPOSIT);}
void createAccount() { accountCreate("Current");}
};

int main()
{

    cur_acct a;
    a.createAccount();
    a.showBal();
    /*account a,b;
    a.accountCreate();
    a.alterBalance(DEPOSIT);
    a.showBalance();
    a.alterBalance(APPLY_PENELTY);
    a.showBalance();
    a.alterBalance(WITHDRAW);
    a.showBalance();
*/

}