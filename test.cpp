/*#include<iostream>
using namespace std;

int main()
{
    string x[3] =
    {"First",    
    "Second",
    "Third"
    };
    for(int i=0;i<3;i++)
    {
        cout<<x[i];
    }
}*/

#include <iostream>
#include <cstdarg>
using namespace std;
void test(int n, string x[]) {
    for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
}
int main() {
    string x[9] = {"Hello", "World", "This", "Might", "Work", "yes", "No", "Anyways", "Cool"};
    test(9,x);
}