///problema 3
#include<iostream>
#include<cstring>
using namespace std;
char t[1001],*p,aux[1001];
int main()
{
    cin.getline(t,1001);
    p=strtok(t," ");
    while(p)
    {
        if(p[0]=='a')
        {
            for(int i=0,j=strlen(p)-1;i<j;i++,j--)
                swap(p[i],p[j]);
        }
        strcat(aux,p);
        strcat(aux," ");
        p=strtok(NULL," ");
    }
    strcpy(t,aux);
    cout<<t;
    return 0;
}
