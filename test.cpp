#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;
int printSize(const std::string& address) {
  std::fstream motd(address.c_str(), std::ios::binary|std::ios::in|std::ios::ate);
  if(motd) {
    std::fstream::pos_type size = motd.tellg();
    //std::cout << address << " " << size << "\n";
    return size;
  } else {
    perror(address.c_str());
  }
}
class testing {
        int a;
        int b;
        int c;
    public:
        void test()
        {
            cout<<"Input\n";
            cin>>a>>b>>c;
        }
    void input(int x, int y, int z)
    {
        a=x;b=y;c=z;
    }
    void show()
    {
        cout<<"Output\n";
        cout<<" "<<a<<"  "<<c<<"  "<<b<<endl;
    }
    ~testing()
    {
        //cout<<"Object destroyed";
    }
};

int main()
{
testing d[5];
cout<<"Number of objects stored:"<<printSize("new.dat")/sizeof(testing)<<endl;
fstream fin;
fin.open("new.dat", ios::in | ios::binary);
for(int i=0; i<printSize("new.dat")/sizeof(testing);i++)
{
fin.read((char *) &d[i], sizeof(testing));
}
fin.close();
for(int i=0;i<printSize("new.dat")/sizeof(testing); i++)
{
    d[i].show();
}
testing x,y;
x.test();
y.test();
fstream fout("new.dat", ios::out | ios::binary | ios::app);
fout.write((char *) &x, sizeof(testing));
fout.close();
fstream fsout("new.dat", ios::out | ios::binary | ios::app);
fsout.write((char *) &y, sizeof(testing));
fsout.close();


    return 0;
}