///Problema 13
#include<iostream>
#include<cmath>
using namespace std;
int n,k;
int main()
{
    cin>>n>>k;
    if(k>0)
    cout<<(int)pow(10.0,(float) n-1)-1+k;
    else
        cout<<(int)pow(10.0,(float) n-1)+8;
    return 0;
}
