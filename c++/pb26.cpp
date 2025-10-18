///problema 26
#include <iostream>
#include<cstring>
using namespace std;
char t[1001];
int main()
{
    cin.getline(t,1001);
    for(int i=0; i<strlen(t); i++)
        if(t[i]==' ' && t[i+1]==' ')
        {
            strcpy(t+i,t+i+1);
            i--;
        }
        cout<<t;
    return 0;
}
