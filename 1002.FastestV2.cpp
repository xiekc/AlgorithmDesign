#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// dp
#define MAXN 50
int arr[MAXN][MAXN];
int dis[MAXN][MAXN];

int main(){
    int t,n,m,k;//test cases, nodes, edges, max level
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        memset(arr,-1,sizeof(arr));
        memset(dis,0xf,sizeof(dis));

        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            cin>>arr[a][b];
            arr[b][a]=arr[a][b];
        }

        for(int i=1;i<=k+1;i++){
            dis[i-1][1]=0;
            for(int j=1;j<=n;j++){
                for(int k=2;k<=n;k++){
                    if(arr[j][k]!=-1){
                        dis[i][k]=min(dis[i][k],dis[i-1][j]+arr[j][k]);
                    }
                }
            }
        }

        if(dis[k+1][n]==0x0f0f0f0f)cout<<-1<<endl;
        else{
            cout<<dis[k+1][n]<<endl;
        }
    }

    return 0;
}