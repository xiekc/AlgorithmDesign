#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
// bfs
#define MAXN 40500
int N;
vector <char>result;
bool visited[MAXN];
int parent[MAXN][2];

struct Board{
    short board[2][4];
    int step;
};
Board ans;

bool succeed(const Board b){
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            if(ans.board[i][j]!=b.board[i][j]){
				return false;
			}
        }
    }
    return true;
}

int fac[10];
void getFac(){
    fac[0]=1;
    for(int i=1;i<10;i++){
        fac[i]=i*fac[i-1];
    }
}
int code(Board b){
    int result=0;
    for(int i=0;i<8;i++){
        int count=0;
        for(int j=i+1;j<8;j++)
            if(b.board[i/4][i%4]>b.board[j/4][j%4])count++;
        result+=count*fac[8-i-1];
    }
    return result;
}

bool bfs(Board root){
    queue<Board>q;
    Board temp;
    visited[code(root)]=true;
    q.push(root);

    while(!q.empty()){
        Board b=q.front();
        q.pop();
//        cout<<endl;
//        for(int i=0;i<2;i++){
//        	for(int j=0;j<4;j++){
//        		cout<<(int)b.board[i][j]<<" ";
//			}
//			cout<<endl;
//		}
        
        if(b.step>N)break;
        if(succeed(b)){
            int par=parent[code(b)][0],step=parent[code(b)][1];
            while(par!=-1){
                result.push_back(step);
                step=parent[par][1];
                par=parent[par][0];
            }
            return true;
        }

        temp=b;
        for(int i=0;i<4;i++)
            swap(temp.board[0][i],temp.board[1][i]);
        if(!visited[code(temp)]){
            temp.step=b.step+1;
            parent[code(temp)][0]=code(b);
            parent[code(temp)][1]='A';
            visited[code(temp)]=true;
            q.push(temp);
        }

        temp=b;
        for(int i=0;i<2;i++){
            int t=temp.board[i][3];
            for(int j=3;j>0;j--){
                temp.board[i][j]=temp.board[i][j-1];
            }
            temp.board[i][0]=t;
        }
        if(!visited[code(temp)]){
            temp.step=b.step+1;
            parent[code(temp)][0]=code(b);
            parent[code(temp)][1]='B';
            visited[code(temp)]=true;
            q.push(temp);    
        }

        temp=b;
        int t=temp.board[0][1];
        temp.board[0][1]=temp.board[1][1];
        temp.board[1][1]=temp.board[1][2];
        temp.board[1][2]=temp.board[0][2];
        temp.board[0][2]=t;

        if(!visited[code(temp)]){
            temp.step=b.step+1;
            parent[code(temp)][0]=code(b);
            parent[code(temp)][1]='C';
            visited[code(temp)]=true;
            q.push(temp);    
        }
    }
    return false;
}

int main(){
    getFac();
    Board init;
    for(int i=0;i<4;i++){
        init.board[0][i]=(i+1);
        init.board[1][4-i-1]=(4+i+1);
    }
    init.step=0;

    while(cin>>N&&N!=-1){
        result.clear();
        memset(visited,0,sizeof(visited));
        memset(parent,0,sizeof(parent));
        parent[code(init)][0]=-1;

        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                cin>>ans.board[i][j];
            }
        }

        if(!bfs(init))cout<<-1<<endl;
        else{ 
            cout<<result.size();
            if(result.size()!=0)cout<<" ";
            for(int i=result.size()-1;i>=0;i--)
                printf("%c",result[i]);
            cout<<endl;
        }
    }

    return 0;
}