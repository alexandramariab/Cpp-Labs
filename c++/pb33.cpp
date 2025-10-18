///problema 33
#include <iostream>
#include<cstring>
using namespace std;
char a[101],b[101];
int ok,l1;
int main()
{
   cin>>a>>b;
    l1=strlen(a);
    for(int i=0;i<l1;i++)
        if(strchr(b,a[i]))
        {cout<<a[i];
    ok=1;}
    if(ok==0)
        cout<<"nu exista";
    return 0;
}
