#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAXN 105
int dp[MAXN][MAXN];
int main(){
    string a,b;
    while(cin>>a>>b){
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=b.size();j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for(int i=1;i<=a.size();i++){
        //     for(int j=1;j<=b.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        cout<<dp[a.size()][b.size()]<<endl; 
    }

    return 0;
}