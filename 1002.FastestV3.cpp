#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// dfs
#define MAXN 50
int arr[MAXN][MAXN];
int dis[MAXN][MAXN];

void dfs(){

}

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
        dfs();

        if(dis[k+1][n]==0x0f0f0f0f)cout<<-1<<endl;
        else{
            cout<<dis[k+1][n]<<endl;
        }
    }

    return 0;
}