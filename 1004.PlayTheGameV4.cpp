#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// WA
// Not Maximum flow problem !!!
#define MAXN 18*2
int fnet[MAXN][MAXN];//flow graph
int matrix[MAXN][MAXN];
int pre[MAXN];

int solve(int n){
    memset(fnet,0,sizeof(fnet));
    int flow=0,s=0,t=2*n+1;
    for(int i=1;i<=n;i++){
        matrix[s][i]=matrix[i+n][t]=0xffffff;
    }

    while(true){
        memset(pre,-1,sizeof(pre));
        queue<int>q;
        q.push(0);
        while(!q.empty()&&(pre[t]==-1)){
            int u=q.front();
            q.pop();

            for(int v=1;v<=t;v++){
                if((pre[v]==-1)&&(fnet[v][u]||fnet[u][v]<matrix[u][v])){
                    pre[v]=u;
                    q.push(v);
                }
            }
        }

        if(pre[t]==-1)break;

        int bot=0xffffff;
        for(int v=t,u=pre[v];u>=0;v=u,u=pre[v]){
            if(fnet[v][u])bot=min(bot,fnet[v][u]);
            else bot=min(bot,matrix[u][v]-fnet[u][v]);
        }

        for(int v=t,u=pre[v];u>=0;v=u,u=pre[v]){
            if(fnet[v][u])fnet[v][u]-=bot;
            else fnet[u][v]+=bot;
        }
        flow+=bot;
    }

    return flow;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>matrix[i][j+n];
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