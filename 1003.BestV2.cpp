#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 310

struct Score{
    Score(){}
    Score(int num,int time):num(num),time(time){}
    int num;
    int time;
};
bool operator < (const Score one,const Score two){
    return (one.num<two.num) || (one.num==two.num&&one.time>two.time);
}

int arr[MAXN];
Score dp[MAXN][MAXN];

int t,n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sort(arr+1,arr+1+n);

        Score ans(0,0);
        for(int i=1;i<=n;i++){
            for(int j=300;j>=0;j--){
                for(int k=300;k>=0;k--){
                    dp[j][k]=max(dp[j][k],dp[j][k]);
                    if(j>=arr[i])  dp[j][k]=max(dp[j][k],Score(dp[j-arr[i]][k].num+1,dp[j-arr[i]][k].time+j));
                    if(k>=arr[i])  dp[j][k]=max(dp[j][k],Score(dp[j][k-arr[i]].num+1,dp[j][k-arr[i]].time+k));
                    ans=max(ans,dp[j][k]);
                }
            }
        }
        cout<<ans.num<<" "<<ans.time<<endl;
    }
}