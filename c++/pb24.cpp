///problema 24
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("atestat.in");
ofstream g("atestat.out");
int n, fr[100];
int main()
{
    while(f>>n)
        fr[n%100]++;
    for(int i=10; i<=99; i++)
        if(fr[i])
            g<<i<<" ";
    return 0;
}

