#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// break ring to string!!!

int dp[210][210];

// bottom up 
// computing order is very important
// array index
int main(){
    int n,arr[210],answer;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i+n]=arr[i];
        }

        memset(dp,0,sizeof(dp));
        for(int i=0;i<2*n-1;i++){//right
            for(int j=i-1;j>=0;j--){//left
                for(int k=j;k<i;k++){
                    dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+arr[j]*arr[k+1]*arr[i+1]);
                }
            }
        }

        answer=0;
        for(int i=0;i<2*n;i++){
            answer=max(answer,dp[i][i+n-1]);
        }
        cout<<answer<<endl;
    }

    return 0;
}