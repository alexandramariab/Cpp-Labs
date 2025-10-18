///Problema 7
#include <iostream>
using namespace std;
int n,a[11][11],maxi=-999999999;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if(a[i][j]>maxi)
                maxi=a[i][j];
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(a[i][j]==maxi)
            cout<<i<<" "<<j<<endl;
    return 0;
}
