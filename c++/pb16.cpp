///Problema 16
#include<iostream>
#include<fstream>
using namespace std;
ofstream g ("atestat.out");
int n,mini=999999999,maxi=-999999999,x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x<mini)
            mini=x;
        if(x>maxi)
            maxi=x;
    }
    if(mini==maxi)
        g<<"Nu exista";
    else
        g<<mini<<" "<<maxi;
    g.close();
    return 0;
}
