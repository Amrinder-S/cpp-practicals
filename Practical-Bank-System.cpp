#define CURRENT_ACCOUNT 0
#define SAVINGS_ACCOUNT 1
#include<iostream>
#include<string>
using namespace std;

class account {
    string CUSTOMER_NAME;
    int ACCOUNT_NUMBER;
    unsigned int ACCOUNT_TYPE;

    public:
    static int ACCOUNT_NUMBER_COUNT;
    
    void createAccount(int x) {
    cout<<"Creating Account Number 000000"<<x<<endl;
    cout<<"Enter Customer Name: ";
    getline(cin, CUSTOMER_NAME);
    acc_type_wrong:
    cout<<"Enter account type(0 - Savings Account, 1 - Current Account) :";
    cin>>ACCOUNT_TYPE;
    if(ACCOUNT_TYPE>1) {
        cout<<"Invalid Account Type.\n";
        goto acc_type_wrong;
    }
    ACCOUNT_NUMBER = x;
    cout<<"Account Number 000000"<<ACCOUNT_NUMBER<<" Created.\n";
    cout<<"Name: "<<CUSTOMER_NAME<<"\nAccount Type: "<<(ACCOUNT_TYPE==0?" Savings Account":" Current Account");
    ACCOUNT_NUMBER_COUNT += 1;
    }

};

int account::ACCOUNT_NUMBER_COUNT = 1;

int main()
{
    account a;
    a.createAccount(account::ACCOUNT_NUMBER_COUNT);

    return 0;
}