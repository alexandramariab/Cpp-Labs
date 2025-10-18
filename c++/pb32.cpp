///problema 32
#include <iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int n,a[21][21],cmmdc;
int Cmmdc(int a,int b)
{
    if(a==0 && b!=0)
        return b;
    else
        if(a!=0 && b==0)
        return a;
    else
        if(a==0 && b==0) return 0;
        else
    {
        while(a!=b)
            if(a>b)
            a=a-b;
        else
            b=b-a;
        return b;
    }
}
int main()
{
   f>>n;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    f>>a[i][j];
    cmmdc=a[1][2];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        cmmdc=Cmmdc(cmmdc,a[i][j]);
    cout<<cmmdc;
    f.close();
    return 0;
}
