///problema 1
#include<iostream>
#include<fstream>
using namespace std;
ifstream f ("date.in");
int n,m,a[21][21];
int main()
{
    f>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        f>>a[i][j];
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=m;i++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
