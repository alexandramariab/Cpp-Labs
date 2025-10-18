///problema 37
#include <iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int n,nr;
int main()
{
    while(f>>n)
    {
        if(n!=1)
        {
            while(n%10==0)
                n=n/10;
            if(n==1)
                nr++;
        }
    }
    if(nr)
    cout<<nr;
    else
        cout<<"nu exista";
    return 0;
}
