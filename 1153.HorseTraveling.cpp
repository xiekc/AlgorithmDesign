#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int board[9][9];
bool solved;
vector<int>v;
const int row=8,column=8;
const int dc[]={-2,-1,1,2,2,1,-1,-2};
const int dr[]={1,2,2,1,-1,-2,-2,-1};
bool isValid(int r,int c){
    return (r>=0)&&(c>0)&&(r<row)&&(c<=column)&&(board[r][c]==0);
}

int nextArr[row+1][column+1];
bool cmp(int a,int b){
    return nextArr[a/column][a%column]<nextArr[b/column][b%column];
}

void backtrack(int r,int c){
    if(solved||!isValid(r,c))return;
    if(v.size()==row*column){
        solved=true;
        cout<<v[0];
        for(int i=1;i<row*column;i++){
            cout<<" "<<v[i];
        }
        cout<<endl;
        return;
    }

    vector<int>temp;
    for(int i=0;i<column;i++){
        if(isValid(r+dr[i],c+dc[i])){
            temp.push_back((r+dr[i])*column+c+dc[i]);
        }
    }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<temp.size()&&(!solved);i++){
        int newr=temp[i]/column,newc=temp[i]%column;
        if(isValid(newr,newc)){
            board[newr][newc]=true;
            v.push_back((newr)*column+newc);
            backtrack(newr,newc);
            board[newr][newc]=false;
            v.pop_back();
        }
    }
}

void getNext(){
    memset(nextArr,0,sizeof(nextArr));
    for(int r=0;r<row;r++){
        for(int c=1;c<=column;c++){
            for(int k=0;k<8;k++){
                if(isValid(r+dr[k],c+dc[k])){
                    nextArr[r][c]++;
                }
            }
        }
    }
}

int main(){
    int start,c,r;
    getNext();
    while(cin>>start&&start!=-1){
        memset(board,0,sizeof(board));
        v.clear();//important!!!
        solved=false;
        r=start/column;
        c=start%column;

        board[r][c]=1;
        v.push_back(start);

        backtrack(r,c);
    }
}