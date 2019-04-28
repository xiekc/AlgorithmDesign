#include <iostream>
#include <cstring>
using namespace std;

int dpArr[101][101];
// increase < or not increase <, there are two ways
void dp(){
    dpArr[1][0]=1;
    for(int i=2;i<=100;i++){
        dpArr[i][0]=1;
        for(int j=1;j<i;j++){
            dpArr[i][j]=((1+i-2-(j-1))*dpArr[i-1][j-1]+(1+j)*dpArr[i-1][j])%2007;
        }
    }
}

int main(){
    memset(dpArr,0,sizeof(dpArr));
    dp();
    int n,k;
    while(scanf("%d %d",&n,&k)==2){
        printf("%d\n",dpArr[n][k]);
    }

    return 0;
}