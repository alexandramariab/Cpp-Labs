///Problema 15
#include<iostream>
using namespace std;
int di[9]={-2,-1,1,2,2,1,-1,-2},dj[9]={1,2,2,1,-1,-2,-2,-1},n,x,y;
int main()
{
    cin>>n>>x>>y;
    for(int k=0;k<8;k++)
        if(x+di[k]>0 && x+di[k]<=n && y+dj[k]>0 && y+dj[k]<=n)
        cout<<x+di[k]<<" "<<y+dj[k]<<"     ";
    return 0;
}
