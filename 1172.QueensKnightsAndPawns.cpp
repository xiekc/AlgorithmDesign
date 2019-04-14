#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 1010
char board[MAXN][MAXN];
int row,column;
// every piece acts as a blocker
bool valid(int r,int c){
    return (r>0)&&(r<=row)&&(c>0)&&(c<=column)&&(board[r][c]!='P')&&(board[r][c]!='Q'&&(board[r][c]!='K'));
}

const int drQ[]={0,-1,-1,-1,0,1,1,1};
const int dcQ[]={-1,-1,0,1,1,1,0,-1};
void queen(vector<pair<int,int> >&queens){
    for(int i=0;i<queens.size();i++){
        for(int j=0;j<8;j++){
            int r=queens[i].first,c=queens[i].second;
            while(valid(r+=drQ[j],c+=dcQ[j])){
                board[r][c]=true;
            }
        }
    }
}

const int drK[]={-1,-2,-2,-1,1,2,2,1};
const int dcK[]={-2,-1,1,2,2,1,-1,-2};
void knight(vector<pair<int,int> >&knights){
    for(int i=0;i<knights.size();i++){
        int r=knights[i].first,c=knights[i].second;
        for(int j=0;j<8;j++){
            if(valid(r+drK[j],c+dcK[j]))board[r+drK[j]][c+dcK[j]]=true;
        }
    }
}

int main(){
    int count=1;
    while(cin>>row>>column&&row!=0){
        memset(board,0,sizeof(board));
        int t,r,c,temp;
        vector<pair<int,int> >queens,knights,pawns;
        cin>>t;
        for(int i=0;i<t;i++){
            cin>>r>>c;
            board[r][c]='Q';
            queens.push_back(make_pair(r,c));
        }

        cin>>t;
        for(int i=0;i<t;i++){
            cin>>r>>c;
            board[r][c]='K';
            knights.push_back(make_pair(r,c));
        }

        cin>>t;
        for(int i=0;i<t;i++){
            cin>>r>>c;
            board[r][c]='P';
            pawns.push_back(make_pair(r,c));
        }

        queen(queens);
        knight(knights);

        int result=0;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=column;j++){
                if(board[i][j]==0)result++;
            }
        }
        // for(int i=1;i<=10;i++){
        //     for(int j=1;j<=10;j++){
        //         cout<<board[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // }
        printf("Board %d has %d safe squares.\n",count,result);
        count++;
    }

    return 0;
}