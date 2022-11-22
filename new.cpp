#include<iostream>
#include<fstream>
using namespace std;

int main()

{

ofstream("filename.txt")
<<"Hello World";
cout<<ifstream("filename.txt").rdbuf();

return 0;
}