///Problema 18
#include<iostream>
using namespace std;
int m,n,x,y;
int main()
{
    cin>>m>>n;
    x=m; y=n;
    while(x!=y)
    {
        if(x>y)
            x=x-y;
        else
            y=y-x;
    }
    cout<<x<<" "<<(m/x)*(n/x);
    return 0;
}
