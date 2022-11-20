#include<iostream>
#include<conio.h>
//#include<cstdlib>
using namespace std;
int main()
{
    char ch;
    while(1)
    {
        ch = getch();
        //system("cls");
        cout<<"You pressed : "<<int(ch)<<endl;
    }
    return 0;
}