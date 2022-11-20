#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#define MAIN_MENU 0
using namespace std;
int menuID = 0;
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);

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
int maxOptions = 4;
string mainMenuOptions[maxOptions] = 
{
"Login.",
"Create Account.",
"Delete Account.",
"Exit"
};
int option=1;

menu(option,maxOptions,mainMenuOptions);
char ch;
while(menuID == MAIN_MENU)
{
    ch = getch();
    if(ch=='P')
    {
        option++;
        if(option>maxOptions)
            option=1;
    }
    if(int(ch)==72)
        {
            option--;
            if(option<1)
                option=maxOptions;
        }
    if(int(ch)==13)
    {
        switch(option)
        {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: exit(3);
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