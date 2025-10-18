///problema 35
#include <iostream>
#include<cstring>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
char s[101],b[101],a[101];
int main()
{
   f>>s>>a>>b;
   if(strlen(a)>strlen(s) || strlen(b)>strlen(s))
    cout<<"NU";
   else
   {
       int ok=1;
       for(int i=0;i<strlen(a) && ok;i++)
        if(a[i]!=s[i])
        ok=0;
       for(int i=strlen(b)-1,j=strlen(s)-1;i>=0 && ok;i--,j--)
        if(b[i]!=s[j])
        ok=0;
        if(ok==0)
            cout<<"NU";
        else
            cout<<"DA";
   }
    return 0;
}
