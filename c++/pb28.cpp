///problema 28
#include <iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int m,n,a[21][21],l,v[21];
int main()
{
   f>>m>>n>>l;
   for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    f>>a[i][j];
    for(int k=1;k<=n;k++)
        f>>v[k];
   for(int i=m;i>=l;i--)
    /// pe linia i+1 copiem linia i
   {
       for(int j=1;j<=n;j++)
        a[i+1][j]=a[i][j];
   }
   for(int j=1;j<=n;j++)
    a[l][j]=v[j];
   for(int i=1;i<=m+1;i++)
   {
       for(int j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
       cout<<endl;
   }
   f.close();
    return 0;
}
