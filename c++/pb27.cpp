///problema 27
#include <iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int m,n,a[21][21],c;
int main()
{
   f>>m>>n>>c;
   for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    f>>a[i][j];
   for(int i=1;i<m;i++)
   {
       for(int j=i+1;j<=m;j++)
        if(a[i][c]>a[j][c])
       {
           for(int k=1;k<=n;k++)
           {
               int aux=a[i][k];
               a[i][k]=a[j][k];
               a[j][k]=aux;
           }
       }
   }
   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
       cout<<endl;
   }
   f.close();
    return 0;
}
