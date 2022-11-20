#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);

class menu {

};

void insertLines (int x) {for(int i=0;i<x;i++)cout<<"\n";}
void mainMenu(int select,int selsize, string *sel[]) {
    for(int i=0;i<selsize;i++) {
        
        if(i!=select)
        {
            SetConsoleTextAttribute(console_color, 15);
            cout<<"      "<<sel[i]<<endl;
        }
        else
        {
            if(select==selsize-1)
                SetConsoleTextAttribute(console_color, 4);
            else
                SetConsoleTextAttribute(console_color, 10);
            cout<<"--->    "<<sel[i]<<"    <---"<<endl;
        }
    }

}
void selectOption (int select, int menuID) {
    system("cls");
    insertLines(4);
    string exxx[5] = {"Option A.","Option B.","Option C.","Option D.", "Exit."};
    if(menuID==0)
        mainMenu(select, 5, &exxx);
    insertLines(4);
    SetConsoleTextAttribute(console_color, 15);
}
int main()
{

    int sel=0;
    char ch;
    int selecting = 1;
    selectOption(0, 0);
    while(selecting) {
        ch = getch();
        if(ch=='P')
        {
            sel++;
            if(sel>3)
            {
                sel=0;
            }
        }
                if(int(ch)==72)
        {
            sel--;
            if(sel<0)
            {
                sel=3;
            }
        }
        selectOption(sel, 0);
        if(int(ch)==13)
            switch(sel)
            {
                case 0: break;
                case 1: break;
                case 2: break;
                case 3: exit(3);
            }

    }
    return 0;
}