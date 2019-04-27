#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int dp[550][550];
int main(){
    int t,a[550],b[550],aSize,bSize;
    cin>>t;
    while(t--){
        cin>>aSize>>bSize;
        for(int i=1;i<=aSize;i++){
            cin>>a[i];
        }
        for(int i=1;i<=bSize;i++){
            cin>>b[i];
        }

        sort(a+1,a+aSize+1);
        sort(b+1,b+bSize+1);

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=aSize;i++){
            for(int j=i;j<=bSize;j++){
                if(i==j)dp[i][j]=dp[i-1][j-1]+abs(b[j]-a[i]);
                else dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(b[j]-a[i]));
            }
        }

        cout<<dp[aSize][bSize]<<endl;
    }

    return 0;
}