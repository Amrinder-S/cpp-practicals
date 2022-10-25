#define PENELTY_AMOUNT 500
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
    static int account_number_count;
    void createAccount();
    void alterBalance(int argument)
    {
        int newBal = 0;
        if(argument==2)
        {
            cout<<"\nService charge of "<<PENELTY_AMOUNT<<" applied to account #"<<account_number<<endl;
            cout<<"Old balance: "<<balance;
            balance-=PENELTY_AMOUNT;
            cout<<" | New balance: "<<balance<<endl;
        }
        else
        {

        cout<<"\nEnter the amount to "<<(argument?"deposit":"withdraw")<<": ";
        cin>>newBal;
        cout<<"Amount "<<newBal<<(argument?" deposited to":" withdrawn from")<<" bank account #"<<account_number<<endl;
        cout<<"Old balance: "<<balance;
        argument? balance+=newBal : balance-=newBal;
        cout<<" | New balance: "<<balance<<endl;
        }
    }
    void showBalance()
    {
        cout<<"\nBalance for Account #"<<account_number<<" : "<<balance<<"\nCustomer Name:"<<customer_name<<endl;
    }

};
int account::account_number_count;

void account::createAccount()
{
        {
        cout<<"\nEnter customer Name:";
        getline(cin >> ws, customer_name, '\n');
        account_number = account::account_number_count;
        cout<<"Account number "<<account::account_number_count<<" Created.\nCustomer Name: "<<customer_name<<"\nBalance: "<<balance<<endl;
        account::account_number_count++;
    }
}

int main()
{
    account a,b;
    a.createAccount();
    a.alterBalance(DEPOSIT);
    a.showBalance();
    a.alterBalance(APPLY_PENELTY);
    a.showBalance();
    a.alterBalance(WITHDRAW);
    a.showBalance();

}