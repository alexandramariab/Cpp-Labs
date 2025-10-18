///Problema 10
#include<iostream>
using namespace std;
int n,m,a[11][11],ma;
int main()
{
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            a[i][0]+=a[i][j];
        }
    for(int i=1;i<=m;i++)
        cout<<(float)a[i][0]/n<<" ";
    return 0;
}
