#include <iostream>
using namespace std;

long long full[100];
long long nfull[100];
int main(){
    int n;
    full[0]=1;
    nfull[0]=0;
    for(int i=1;i<=15;i++){
        full[i]=3*full[i-1]+nfull[i-1];
        nfull[i]=2*full[i-1]+nfull[i-1];
    }
    while(cin>>n&&n!=-1){
        if(n%2==1)cout<<0<<endl;
        else cout<<full[n/2]<<endl;
    }

    return 0;
}