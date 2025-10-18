///problema 2
#include<iostream>
using namespace std;
int n, s;
int main()
{
    cin>>n;
    while(n)
    {
        if(n%2==0)
            s=s+n;
        n=n/10;
    }
    cout<<s;
    return 0;
}
