#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#define MAIN_MENU 0
using namespace std;
int menuID = 0;
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
void insertLines (int x) {for(int i=0;i<x;i++)cout<<"\n";}

void menu(int option, int size,string x[])
{
    system("cls");
    for(int i=0;i<size;i++)
    {
        if(option==(i+1))
        {
            if(i==size-1) SetConsoleTextAttribute(console_color, 4); else SetConsoleTextAttribute(console_color, 10);
            cout<<"--->   "<<x[i]<<"   <--\n";
            SetConsoleTextAttribute(console_color, 15);
        }
        else
            cout<<x[i]<<"\n";
    }
}

void mainMenu()
{
int maxOptions = 6; // Max Options means number of items in the menu
string mainMenuOptions[maxOptions] = 
{
"New Account",
"Deposit Amount.",
"Withdraw Amount.",
"Balance Enquiry.",
"Delete Account.",
"Exit"
};
int option=1;

menu(option,maxOptions,mainMenuOptions);
char ch;
while(menuID == MAIN_MENU) // Main menu bool, to keep track of when main menu is visible
{
    ch = getch(); //getting the pressed key
    if(ch=='P') //Down key
    {
        option++;
        if(option>maxOptions)
            option=1;
    }
    if(int(ch)==72) //Up key
        {
            option--;
            if(option<1)
                option=maxOptions;
        }
    if(int(ch)==13) //if enter was pressed
    {
        switch(option)
        {
            case 1:
                menuID = 1; 
                write_account();
                break;
            case 2: 
                menuID = 2;
                deposit_withdraw(num, 1);
                break;
            case 3: //menuID = 3;
                break;
            case 6: exit(3);
        }
    }
    menu(option,maxOptions,mainMenuOptions);
    
}
}

int main()
{

mainMenu();
return 0;
}