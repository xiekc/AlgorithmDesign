#include <iostream>
#include <cstring>
using namespace std;

#define MAX 0x7ffff
#define MAXN 110
int graph[MAXN][MAXN];
int dis[MAXN];

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dis[i]=MAX;
        for(int j=1;j<=n;j++){
            graph[i][j]=MAX;
        }
    }

    int a,b,weight;
    for(int i=0;i<k;i++){
        cin>>a>>b>>weight;
        graph[a][b]=min(graph[a][b],weight);
        if(a==1)dis[b]=min(dis[b],weight);
    }

    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j]<MAX){
                dis[j]=min(dis[j],dis[i]+graph[i][j]);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<(graph[i][j]>=MAX?0:graph[i][j])<<" ";
    //     }
    //     cout<<endl;
    // }

    int flag=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j]<MAX&&(dis[i]+graph[i][j]<dis[j])){
                flag=1;
                break; 
            }
        }
    }

    // for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    // cout<<endl;
    if(dis[n]>=MAX)cout<<"-1\n";
    else if(flag==1)cout<<"0\n";
    else cout<<dis[n]<<endl;

    return 0;
}