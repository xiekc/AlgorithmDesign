#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

#define MAXN 110
bool edge[MAXN][MAXN],visited[MAXN];
int inDegree[MAXN],depth[MAXN],width[MAXN];
int nodes,edges;

bool dfs(int root,int parent){
    if(visited[root]==true)return false;

    visited[root]=true;
    depth[root]=depth[parent]+1;
    width[depth[root]]++;

    for(int i=1;i<=nodes;i++){
        if(edge[root][i]){
            if(dfs(i,root)==false)return false;
        }
    }
    return true;
}

int main(){
    int a,b;
    while(cin>>nodes>>edges&&nodes!=0){
        memset(edge,0,sizeof(edge));
        memset(inDegree,0,sizeof(inDegree));
        memset(visited,0,sizeof(visited));
        memset(depth,0,sizeof(depth));
        memset(width,0,sizeof(width));
        depth[0]=-1;

        for(int i=0;i<edges;i++){
            cin>>a>>b;
            edge[a][b]=true;//from a to b
            inDegree[b]++;
        }

        if(edges>=nodes){
            cout<<"INVALID\n";
            continue;
        }

        bool findRoot=false,forest=true;
        for(int i=1;i<=nodes;i++){
            if(inDegree[i]==0){
                findRoot=true;
                if(!dfs(i,0)){
                    forest=false;
                }
            }
        }
        // test case: 3 2; 1 2; 2 1;
        for(int i=1;i<=nodes;i++){
            if(!visited[i])forest=false;
        }

        if(!findRoot||!forest)cout<<"INVALID\n";
        else {
            int maxDepth=0,maxWidth=0;
            for(int i=1;i<=nodes;i++){
                maxDepth=max(maxDepth,depth[i]);
            }

            for(int i=0;i<=nodes;i++){
                maxWidth=max(maxWidth,width[i]);
            }
            cout<<maxDepth<<" "<<maxWidth<<endl;
        }

    }

    return 0;
}