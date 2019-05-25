#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
// max flow
#define MAXN 220
int cap[MAXN][MAXN];
int fnet[MAXN][MAXN];
int parent[MAXN];
int main(){
    int girls,boys,total,dest;
    int flow;
    while(cin>>girls>>boys){
        flow=0;
        total=girls+boys;
        dest=total+1;
        memset(cap,0,sizeof(cap));
        memset(fnet,0,sizeof(fnet));
        for(int i=1;i<=girls;i++){
            cap[0][i]=1;
            for(int j=girls+1;j<=total;j++){
                cin>>cap[i][j];
            }
        }
        for(int i=girls+1;i<=total;i++){
            cap[i][dest]=1;
        }

        while(true){
            for(int i=0;i<=dest;i++){
                parent[i]=-1;
            }
            queue<int>q;
            q.push(0);
            while(!q.empty()&&parent[dest]==-1){
                int u=q.front();
                // cout<<u<<endl;
                q.pop();

                for(int i=1;i<=dest;i++){
                    if(parent[i]==-1){
                        if(cap[u][i]>fnet[u][i]||fnet[i][u]){
                            parent[i]=u;
                            q.push(i);
                        }
                    }
                }
            }
            if(parent[dest]==-1)break;

            int bottle=0xffffff;
            for(int i=dest,j=parent[i];j>=0;i=j,j=parent[i]){
                if(fnet[i][j])bottle=min(bottle,fnet[i][j]);
                else bottle=min(bottle,cap[j][i]-fnet[j][i]);
            }
            for(int i=dest,j=parent[i];j>=0;i=j,j=parent[i]){
                if(fnet[i][j])fnet[i][j]-=bottle;
                else fnet[j][i]+=bottle;
            }
            flow+=bottle;
        }

        cout<<flow<<endl;
    }

    return 0;
}