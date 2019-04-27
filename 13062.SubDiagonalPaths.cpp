#include <iostream>
#include <cstring>
using namespace std;
//long long !!!
long long dp[35][35];
int main(){
    int n;
    while(cin>>n&&n!=0){
        memset(dp,0,sizeof(dp));

        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        cout<<dp[n][n]<<endl;
    }
    

    return 0;
}