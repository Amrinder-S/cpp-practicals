#include <iostream>
#include <windows.h>

using namespace std;
  

int main()
{
    // Color of the console
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
  
    for (int P = 1; P < 50; P++) {
  
        SetConsoleTextAttribute(
            console_color, P);

        cout << P << " Hello Geeks, "
             << "good night!!!\n";
    }
  
    return 0;
}