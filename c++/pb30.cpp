///problema 30
#include <iostream>
using namespace std;
int a,b,c,n;
int main()
{
   cin>>n;
   if(n%3==0)
    a=b=c=n/3;
   else if(n%3==1)
    a=n/3+1,b=c=n/3;
    else a=b=n/3+1,c=n/3;
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}

