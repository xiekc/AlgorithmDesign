#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int board[6][7];
bool solved;
vector<int>v;
const int dc[]={-2,-1,1,2,2,1,-1,-2};
const int dr[]={1,2,2,1,-1,-2,-2,-1};
bool isValid(int r,int c){
    return (r>=0)&&(c>0)&&(r<5)&&(c<=6)&&(board[r][c]==0);
}

void backtrack(int r,int c){
    if(solved)return;
    if(v.size()==30){
        solved=true;
        cout<<v[0];
        for(int i=1;i<30;i++){
            cout<<" "<<v[i];
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<8&&(!solved);i++){
        int newr=r+dr[i],newc=c+dc[i];
        if(isValid(newr,newc)){
            board[newr][newc]=true;
            v.push_back((newr)*6+newc);
            backtrack(newr,newc);
            board[r+dr[i]][newc]=false;
            v.pop_back();
        }
    }
}


int main(){
    int start,c,r;
    while(cin>>start&&start!=-1){
        memset(board,0,sizeof(board));
        v.clear();//important!!!
        solved=false;
        c=start%6;
        r=start/6;

        board[r][c]=1;
        v.push_back(start);

        backtrack(r,c);
    }
}