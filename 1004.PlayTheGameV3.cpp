#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;
// AC
#define MAXN 18
int dp[1<<MAXN];//row, column, not contained column
int matrix[MAXN][MAXN];

int onebits(int num){
    int sum=0;
    while(num){
        if(num&1)sum++;
        num>>=1;
    }
    return sum;
}

int solve(int n){
    memset(dp,0,sizeof(dp));
    for(int i=1;i < 1<<n;i++){
        int length=onebits(i);
        for(int t=i,bit=0;t;t>>=1,bit++){
            if(i&(1<<bit)){
                dp[i]=max(dp[i],dp[i^(1<<bit)]+matrix[length-1][bit]);
            }
        }
    }

    return dp[(1<<n)-1];
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
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