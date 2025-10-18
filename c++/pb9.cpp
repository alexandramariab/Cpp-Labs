///Problema 9
#include<iostream>
using namespace std;
int n,fr[10],nr;
int main()
{
    cin>>n;
    while(n>9)
    {
        fr[n%10]++;
        n/=10;
    }
    for(int i=n+1; i<=9; i++)
        nr+=fr[i];
    cout<<nr;
    return 0;
}
