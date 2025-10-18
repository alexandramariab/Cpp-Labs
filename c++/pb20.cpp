///Problema 20
#include<iostream>
#include<cstring>
using namespace std;
int n;
char t[301],cuv[31];
int main()
{
    cin>>n;
    cin>>cuv;
    cuv[0]=toupper(cuv[0]);
    for(int i=1;i<strlen(cuv);i++)
        cuv[i]=tolower(cuv[i]);
        strcpy(t,cuv);
        strcat(t," ");
    for(int i=2;i<=n;i++)
    {
        cin>>cuv;
    for(int j=0;j<strlen(cuv);j++)
        cuv[j]=tolower(cuv[j]);
    strcat(t,cuv);
    strcat(t," ");
    }
    t[strlen(t)-1]='.';
    cout<<t;
    return 0;
}
