#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAXN 310

struct node{
    int one;
    int two;
    int total;
};

int arr[MAXN];
int dp[MAXN][MAXN];
bool visited[MAXN];

int t,n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        // memset(arr,-1,sizeof(arr));
        memset(visited,0,sizeof(visited));

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        // int mi=-1;
        // int one=300,two=300
        for(int i=1;i<n;i++){
            
        }
    }
}