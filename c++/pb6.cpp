///Problema 6
#include <iostream>
#include<cstring>
using namespace std;
char aux[1001],t[1001],*p;
int main()
{
    cin.getline(t,1001);
    p=strtok(t," ");
    while(p)
    {
        if(p[0]=='a');
        else
        {
            strcat(aux,p);
            strcat(aux," ");
        }
        p=strtok(NULL," ");
    }
    strcpy(t,aux);
    cout<<t;
    return 0;
}
