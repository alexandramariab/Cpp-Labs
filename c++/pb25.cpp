///problema 25
#include <iostream>
using namespace std;
int n, nr[100];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>nr[i];
    for(int i=1,j=n; i<j; i++,j--)
    {
        if(nr[i]!=nr[j])
        {
            int st=0,dr=0;
            for(int k=1; k<=nr[i]; k++)
                if(nr[i]%k==0)
                    st++;
            for(int k=1; k<=nr[j]; k++)
                if(nr[j]%k==0)
                    dr++;
            if(st==dr)
                cout<<nr[i]<<','<<nr[j]<<endl;
        }
    }
    return 0;
}
