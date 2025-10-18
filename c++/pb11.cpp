///Problema 11
#include<iostream>
#include<cstring>
using namespace std;
char t[1001],*p;
int nr;
int main()
{
    cin.getline(t,1001);
    p=strtok(t," ");
    while(p)
    {
        nr++;
        p=strtok(NULL," ");
    }
    cout<<nr;
    return 0;
}
