///problema 38
#include <iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int n,m,nr,fr[101],x;
int main()
{
    f>>m;
    for(int i=1; i<=m; i++)
        f>>x,fr[x]=1;
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>x;
        if(fr[x]==1)
        {
            cout<<x<<" ";
            nr++;
        }
    }
    cout<<endl;
    if(nr)
        cout<<nr;
    else
        cout<<"intersectie vida";
    return 0;
}
