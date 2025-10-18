///Problema 17
#include<iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int fr[10],x;
int main()
{
    while(f>>x)
    {
        fr[x]++;
    }
    for(int i=9;i>=0;i--)
        for(int j=1;j<=fr[i];j++)
        cout<<i;
    f.close();
    return 0;
}
