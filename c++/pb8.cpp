///Problema 8
#include<iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int n,ok,x,y;
int main()
{
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>x;
        if(ok==0)
        {
            y=x;
            while(x>9)
                x=x/10;
            if(x==7)
            {
                cout<<y;
                ok=1;
            }
        }
    }
    f.close();
    return 0;
}
