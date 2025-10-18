///Problema 19
#include<iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int lmax,l,x,y,c;
int main()
{
    l=1;
    f>>x;
    while(f>>y)
    {
        if(x==y)
            l++;
        else
        {
            if(l>lmax)
            {
                lmax=l;
                c=x;
            }
            l=1;
        }
        x=y;
    }
    if(l>lmax)
    {
        lmax=l;
        c=x;
    }
    cout<<lmax<<" "<<c;
    f.close();
    return 0;
}
