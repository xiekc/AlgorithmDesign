#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// optimal matching
// unfinished
// references:
// https://www.cnblogs.com/wenruo/p/5264235.html
// https://www.cnblogs.com/logosG/p/logos.html
#define MAXN 18*2
int row[MAXN];
int column[MAXN];
int matrix[MAXN][MAXN];
int n;
bool visited[MAXN];
int matched[MAXN];

bool match(int r){
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            if(matched[i]==-1||match(matched[i])){
                matched[i]=r;
                return true;
            }
        }
    }
    return false;
}

int solve(){
    memset(matched,-1,sizeof(matched));
    memset(column,0,sizeof(column));
    memset(row,0,sizeof(row));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            row[i]=max(row[i],matrix[i][j]);
    }

    for(int i=0;i<n;i++){
        while(true){
            memset(visited,0,sizeof(visited));

        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }

        cout<<solve()<<endl;
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