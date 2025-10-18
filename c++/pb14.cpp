///Problema 14
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
ofstream g ("atestat.out");
int fr[10],x;
int main()
{
    while(f>>x)
    {
        fr[x/100%10]++;
    }
    x=-1;
    for(int i=0;i<=9;i++)
        if(fr[i]>x)
        x=fr[i];
    g<<x;
    f.close();
    g.close();
    return 0;
}
