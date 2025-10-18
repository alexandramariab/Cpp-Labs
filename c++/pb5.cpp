///Problema 5
#include <iostream>
using namespace std;
int n,maxi,x;
int main()
{
    cin>>n;
    while(n>=100)
    {
        x=n%1000;
        if(maxi<x)
            maxi=x;
        n=n/10;
    }
    cout<<maxi;
    return 0;
}
