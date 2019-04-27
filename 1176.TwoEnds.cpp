#include <iostream>
#include <cstring>
using namespace std;

// bottom up
int dp[1010];
int main(){
    int n,arr[1010];
    while(cin>>n&&n!=0){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        memset(dp,0,sizeof(dp));
        //from center to end
        dp[0]=max(arr[n/2-1],arr[n/2]);
        for(int i=1,le=n/2-1,ri=n/2;le>=0&&ri<n;le--,ri++,i++){
            dp[1]=max(dp[0])
        }

        cout<<dp[0]<<endl;
    }

    return 0;
}