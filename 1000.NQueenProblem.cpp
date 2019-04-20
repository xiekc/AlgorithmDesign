#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN 10
int board[MAXN];
int len;

bool isValid(int r,int c){
    for(int i=0;i<c;i++){
        if(board[i]==r)return false;
        if(abs(board[i]-r)==c-i)return false;
    }

    return true;
}

int queen(int cur){
    int sum=0;
    if(cur==len){
        return 1;
    }

    for(int i=0;i<len;i++){
        if(isValid(i,cur)){
            board[cur]=i;
            sum+=queen(cur+1);
        }
    }

    return sum;
}

int main(){
    while(cin>>len){
        memset(board,0,sizeof(board));
        cout<<queen(0)<<endl;
    }

    return 0;
}