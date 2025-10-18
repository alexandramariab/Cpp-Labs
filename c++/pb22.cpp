//problema 22

#include <iostream>
#include<cstring>

using namespace std;

char v[100][30], t[100][30], aux[30];
int n;

int main()
{
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        strcpy(t[i],v[i]);
        for(int j=0; j<strlen(t[i]);j++){
            t[i][j] = tolower(t[i][j]);
        }
    }

    for(int i=1; i< n; i++){
        for(int j=i+1; j<=n; j++){
            if(strcmp(t[i], t[j])>0){
                strcpy(aux, t[i]);
                strcpy(t[i], t[j]);
                strcpy(t[j], aux);

                strcpy(aux, v[i]);
                strcpy(v[i], v[j]);
                strcpy(v[j], aux);
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout<<v[i]<<" ";

    return 0;
}
