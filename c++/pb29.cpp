///problema 29
#include <iostream>
#include<cstring>
using namespace std;
char t[101];
int main()
{
   cin.getline(t,101);
   for(int i=0;i<strlen(t);i++)
    if(strchr("aeiouAEIOU",t[i])!=NULL && t[i]!=' ')
    cout<<t[i];
   for(int i=strlen(t)-1;i>=0;i--)
    if(strchr("aeiouAEIOU",t[i])==NULL && t[i]!=' ')
    cout<<t[i];
    return 0;
}

