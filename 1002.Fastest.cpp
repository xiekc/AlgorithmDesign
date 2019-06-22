#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// bfs
#define MAXN 50
#define code(x,i) (x+(1<<(i-1)))
int arr[MAXN][MAXN];
bool visited[1100];

struct node{
    node(int n,int dis,int level,int state):n(n),dis(dis),level(level),state(state){}
    int n;
    int dis;
    int level;
    int state;
};
int t,n,m,k;
int minimum;
void bfs(){
    memset(visited,0,sizeof(visited));
    queue<node>q;
    q.push(node(1,0,-1,1));
    visited[1]=true;
    while(!q.empty()){
        node t=q.front();
        q.pop();
        if(t.level>k)return;
        // cout<<t.n<<"\n";
        if(t.n==n){
            minimum=min(minimum,t.dis);
            continue;
        };
        for(int i=2;i<=n;i++){
            // cout<<"dis"<<t.n<<i<<" "<<arr[t.n][i]<<endl;
            if(arr[t.n][i]!=-1&&!visited[code(t.state,i)]){
                q.push(node(i,t.dis+arr[t.n][i],t.level+1,code(t.state,i)));
                visited[code(t.state,i)]=true;
            }
        }
    }

    return;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        memset(arr,-1,sizeof(arr));
        memset(visited,0,sizeof(visited));

        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            cin>>arr[a][b];
            arr[b][a]=arr[a][b];
        }

        minimum=0xffffff;
        bfs();
        if(minimum==0xffffff)cout<<-1<<endl;
        else{
            cout<<minimum<<endl;
        }
    }
}