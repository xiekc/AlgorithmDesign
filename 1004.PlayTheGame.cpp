#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 20
int dp[MAXN][MAXN][MAXN];//row, column, not contained column
int matrix[MAXN][MAXN];
// WA
// 虽然保证不重复k，都是j可能选了2次
int solve(int n){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                // if(k!=j)
                for(int m=1;m<=n;m++){
                    if((m!=j&&m!=k)||i==1)
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][m][k]+matrix[i][j]);
                }
            }
        }
    }

    cout<<endl;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    cout<<dp[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    cout<<endl;

    int sum=0;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){    
            sum=max(sum,dp[n][i][k]);
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
1 2 3 5 4
8 7 6 4 8
8 6 5 2 4
5 6 7 8 5
3 2 1 2 3

1 2 3 5 4
13 12 11 8 13
21 19 18 13 16
24 24 26 27 24
30 31 30 30 32

1 2 3 5 4
13 12 11 8 13
21 19 18 14 17
23 27 28 29 25
30 31 30 30 32

1 2 3 5 4
13 12 11 8 13
21 19 18 14 17
24 27 28 29 25
30 31 30 29 32

1 2 3 5 4
12 11 10 8 11
21 19 18 14 17
24 27 28 29 25
29 30 28 30 31

1 2 3 5 4
13 12 11 7 13
20 19 18 14 17
24 27 28 29 25
30 31 30 30 32


32

 */