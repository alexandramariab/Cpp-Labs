///Problema 21
#include<iostream>
using namespace std;
int m,n,a[11][11],s;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        cin>>a[i][j];
    for(int j=1;j<=n;j++)
        s=s+a[1][j]+a[m][j];
    for(int i=2;i<m;i++)
        s=s+a[i][1]+a[i][n];
    cout<<s;
    return 0;
}
