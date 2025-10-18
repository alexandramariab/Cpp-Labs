///problema 40
#include<iostream>
#include<cstring>
using namespace std;
char t[1001];
bool majuscule[300];
int main()
{
    cin.getline(t,1001);

    for(int i = 0; i< strlen(t); i++){
        majuscule[t[i]] = true;
    }

    bool aGasit = false;

    for(char i = 'A'; i <= 'Z'; i++){
        if(majuscule[i]){
            cout<<i;
            aGasit = true;
        }
    }

    if(!aGasit) cout<<"nu exista";
    cout<<endl;

    return 0;
}
