///problema 39
#include <iostream>
using namespace std;
int prim(int x)
{
    if(x<=1)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    for(int i=3; i*i<=x; i=i+2)
        if(x%i==0)
            return 0;
    return 1;
}
int n,m,nr,a[101][101];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];
    for(int i=2; i<=n; i=i+2)
        for(int j=1; j<=m; j++)
            if(prim(a[i][j])==1)
                nr++;
    cout<<nr;
    return 0;
}
