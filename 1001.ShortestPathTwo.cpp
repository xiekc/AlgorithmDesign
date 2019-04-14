#include <iostream>
#include <cstring>
using namespace std;

#define MAX 0x7ffffff
#define MAXN 110
int graph[MAXN][MAXN];
int dis[MAXN][MAXN];

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=MAX;
            graph[i][j]=MAX;
        }
        dis[i][i]=graph[i][i]=0;
    }

    int a,b,weight;
    for(int i=0;i<k;i++){
        cin>>a>>b>>weight;
        dis[a][b]=graph[a][b]=min(graph[a][b],weight);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<(graph[i][j]>=MAX?0:graph[i][j])<<" ";
    //     }
    //     cout<<endl;
    // }


    // for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    // cout<<endl;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(dis[a][b]>=MAX)cout<<"-1\n";
        else cout<<dis[a][b]<<endl;
    }
    return 0;
}