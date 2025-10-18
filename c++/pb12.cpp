///Problema 12
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
ofstream g ("atestat.out");
int x,y;
int main()
{
    f>>x;
    if(x%2==1)
        g<<x<<" ";
    while(f>>y)
    {
        if(y%2==1 && y!=x)
        g<<y<<" ";
        x=y;
    }
    f.close();
    g.close();
    return 0;
}
