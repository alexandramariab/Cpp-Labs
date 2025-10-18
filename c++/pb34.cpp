///problema 34
#include <iostream>
using namespace std;
int v[21],n;
int patrat(int a)
{
    int i;
    for(i=1;i*i<a;i++);
    if(i*i==a)
        return 1;
    else
        return 0;
}
int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
    cin>>v[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        if(patrat(v[i]) && patrat(v[j]))
        if(v[i]>v[j])
    {
        int aux=v[i];
        v[i]=v[j];
        v[j]=aux;
    }
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    return 0;
}
