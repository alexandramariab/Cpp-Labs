///problema 31
#include <iostream>
#include<fstream>
using namespace std;
ifstream f ("atestat.in");
int n,c,ok,N;
int main()
{
   f>>n;
   c=n%10;
   while(f>>n)
   {
       int aux=n;
       while(n>9)
        n=n/10;
       if(n==c)
        N=aux,ok=1;
   }
   if(ok==0)
    cout<<"Nu exista";
   else
   cout<<N;
    return 0;
}
