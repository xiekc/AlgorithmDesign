#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[15][2010]; //long long!!!
ll sum[15][2010];
int main(){
    int t,m,n;
    while(cin>>t){
        for(int i=1;i<=t;i++){
            cin>>n>>m;
            memset(dp,0,sizeof(dp));
            memset(sum,0,sizeof(sum));
            for(int j=1;j<=m;j++){
                dp[1][j]=1;
                sum[1][j]=j;
            }
            for(int j=2;j<=n;j++){
                for(int k=1;k<=m;k++){
                    dp[j][k]=sum[j-1][k/2];
                    sum[j][k]=sum[j][k-1]+dp[j][k];
                }
            }
            printf("Case %d: n = %d, m = %d, # lists = %lld\n",i,n,m,sum[n][m]);
        }
    }

    return 0;
}