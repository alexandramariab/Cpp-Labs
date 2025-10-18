///problema 23
#include <iostream>
using namespace std;
int n,ok;
int main()
{
    cin>>n;
    if(n%2==0)
        n++;
    else
        n=n+2;
    while (ok!=1)
    {
        ok=1;
        for(int i=3; i*i<=n && ok; i=i+2)
            if(n%i==0)
                ok=0;
        if(ok==0)
            n=n+2;
    }
    cout<<n;
    return 0;
}
