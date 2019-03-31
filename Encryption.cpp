#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[1010][1010];
int main(){
    string a,b;
    while(cin>>a>>b){
        int n=a.size(),m=b.size();
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}