///Problema 4
#include <iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int n,nr,x,y;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x;
        y=x;
        while(x%2==0 && x>0)
            x=x/2;
        if(x==1)
        {nr++;
        cout<<y<<" ";}
    }
    if(nr==0)
    cout << 0;
    return 0;
}
