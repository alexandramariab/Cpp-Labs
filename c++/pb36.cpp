///problema 36
#include <iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int suma(int x[101][101],int n,int p)
{
    int s=0;
    for(int i=1;i<=n;i++)
        s=s+x[p][i];
    return s;
}
int n,a[101][101];
int main()
{
   f>>n;
   for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    f>>a[i][j];
    for(int i=1;i<=n;i++)
        if(suma(a,n,i)%2==0)
        cout<<i<<" ";
    return 0;
}
