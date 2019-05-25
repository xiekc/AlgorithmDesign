#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 100
char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
const int dc[]={-1,0,1,0},dr[]={0,-1,0,1};

int main(){
    int row,col;
    cin>>row>>col;
    memset(map,0,sizeof(map));
    memset(visited,0,sizeof(visited));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>map[i][j];
        }
    }

    queue<pair<int,int> >q;
    q.push(make_pair(0,0));
    visited[0][0]=true;
    bool flag=false;
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        if(t.first==row-1&&t.second==col-1){
            flag=true;
            break;
        }

        for(int i=0;i<4;i++){
            int r=t.first+dr[i],c=t.second+dc[i];
            if(!visited[r][c]&&map[r][c]=='.'){
                visited[r][c]=true;
                q.push(make_pair(r,c));
            }
        }
    }

    if(flag)cout<<"yes\n";
    else cout<<"no\n";

    return 0;
}

/*
3 5
...**
*..**
**.**

3 5
...**
*..**
**...


5 5
...**
*..**
**...
..**.
**...
*/