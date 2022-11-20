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
    
    account() {
    cout<<"\n\nCreating Account Number 000000"<<ACCOUNT_NUMBER_COUNT<<endl;
    cout<<"Enter Customer Name: ";
    getline(cin >> ws, CUSTOMER_NAME, '\n');
    acc_type_wrong:
    cout<<"Enter account type(0 - Savings Account, 1 - Current Account) :";
    cin>>ACCOUNT_TYPE;
    if(ACCOUNT_TYPE>1) {
        cout<<"Invalid Account Type.\n";
        goto acc_type_wrong;
    }
    ACCOUNT_NUMBER = ACCOUNT_NUMBER_COUNT;
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
   ofstream wf("bank.dat", ios::out | ios::binary);
   if(!wf) {
      cout << "Cannot open file!" << endl;
      return 1;
    account accs[3];
   for(int i = 0; i < 3; i++)
      wf.write((char *) &accs[i], sizeof(account));
   wf.close();

   /* --------------------------------------- */
   ifstream rf("student.dat", ios::out | ios::binary);
   if(!rf) {
      cout << "Cannot open file!" << endl;
      return 1;
   }
   Student rstu[3];
   for(int i = 0; i < 3; i++)
      rf.read((char *) &rstu[i], sizeof(Student));
   rf.close();
   if(!rf.good()) {
      cout << "Error occurred at reading time!" << endl;
      return 1;
   }
   cout<<"Student's Details:"<<endl;
   for(int i=0; i < 3; i++) {
      cout << "Roll No: " << wstu[i].roll_no << endl;
      cout << "Name: " << wstu[i].name << endl;
      cout << endl;
   }
   return 0;
    return 0;
}