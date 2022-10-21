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
    cout<<"\n\nCreating Account Number 000000"<<x<<endl;
    cout<<"Enter Customer Name: ";
    getline(cin >> ws, CUSTOMER_NAME, '\n');
    acc_type_wrong:
    cout<<"Enter account type(0 - Savings Account, 1 - Current Account) :";
    cin>>ACCOUNT_TYPE;
    if(ACCOUNT_TYPE>1) {
        cout<<"Invalid Account Type.\n";
        goto acc_type_wrong;
    }
    ACCOUNT_NUMBER = x;
    cout<<" ";
    for(int i=0;i<77+CUSTOMER_NAME.length();i++)
        cout<<"_";//77+
    cout<<"\n| Account Number 000000"<<ACCOUNT_NUMBER<<" Created. ";
    cout<<"| Name: "<<CUSTOMER_NAME<<" | Account Type: "<<(ACCOUNT_TYPE==0?" | Savings Account |":" | Current Account |")<<endl<<" ";
        for(int i=0;i<77+CUSTOMER_NAME.length();i++)
        cout<<"_";
    ACCOUNT_NUMBER_COUNT += 1;
    }

};

int account::ACCOUNT_NUMBER_COUNT = 1;
int x= account::ACCOUNT_NUMBER_COUNT;
int main()
{
    account a[3];
    a[0].createAccount(x);
    a[1].createAccount(x);
    a[2].createAccount(x);
    return 0;
}