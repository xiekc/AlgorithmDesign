#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 20
pair<int,int> dp[MAXN][MAXN][MAXN];//row, column, not contained column
int matrix[MAXN][MAXN];
// WA
int solve(int n){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int m=1;m<=n;m++){
                    if(((m!=j)&&((dp[i-1][m][j].second&(1<<(j-1)))==0)&&(dp[i-1][m][j].first+matrix[i][j]>dp[i][j][k].first))||(i==1))
                        dp[i][j][k]=make_pair(dp[i-1][m][j].first+matrix[i][j],dp[i-1][m][j].second|(1<<(j-1)));
                }
            }
        }
    }

    // cout<<endl;
    // for(int k=1;k<=n;k++){
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //                 cout<<dp[i][j][k].first<<" ";
    //             }
    //             cout<<endl;
    //         }
    //         cout<<endl;
    //     }
    // cout<<endl;

    int sum=0;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){    
            sum=max(sum,dp[n][i][k].first);
        }
    }
    return sum;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>matrix[i][j];
            }
        }

        cout<<solve(n)<<endl;
    }
    
}

/*
1
5
4 5 1 9 8 
5 9 9 3 8 
7 7 0 2 2 
0 7 6 0 4 
4 9 9 3 5 

the solution is 40(9 8 7 7 9)
 */