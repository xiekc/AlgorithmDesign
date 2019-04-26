#include <iostream>
#include <vector>
using namespace std;
// iterative deepening
// 没有判重
int N;
bool findRe;
vector <char>result;
struct Board{
    int board[2][4];
    // char perv;
};
Board ans;

bool succeed(const Board b){
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            if(ans.board[i][j]!=b.board[i][j])return false;
        }
    }
    
    return true;
}

bool dfs(Board b,int step){
    if(step>N||findRe)return false;

    if(succeed(b)){
        findRe=true;
        cout<<step;
        if(step!=0)cout<<" ";
        return true;
    }

    bool re=false;
    Board temp;
    temp=b;
    for(int i=0;i<4;i++)
        swap(temp.board[0][i],temp.board[1][i]);
    if(dfs(temp,step+1)){
        re=true;
        result.push_back('A');
    }

    temp=b;
    for(int i=0;i<2;i++){
        int t=temp.board[i][3];
        for(int j=3;j>0;j--){
            temp.board[i][j]=temp.board[i][j-1];
        }
        temp.board[i][0]=t;
    }
    // for(int i=0;i<2;i++){
    //         for(int j=0;j<4;j++){
    //             cout<<temp.board[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // cout<<endl;
    if(dfs(temp,step+1)){
        re=true;
        result.push_back('B');
    }

    temp=b;
    int t=temp.board[0][1];
    temp.board[0][1]=temp.board[1][1];
    temp.board[1][1]=temp.board[1][2];
    temp.board[1][2]=temp.board[0][2];
    temp.board[0][2]=t;
    if(dfs(temp,step+1)){
        re=true;
        result.push_back('C');
    }

    return re;
}

int main(){
    Board init;
    for(int i=0;i<4;i++){
        init.board[0][i]=(i+1);
        init.board[1][4-i-1]=(4+i+1);
    }
    int n;
    while(cin>>n&&n!=-1){
        result.clear();
        findRe=false;
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                cin>>ans.board[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            N=i;
            if(dfs(init,0)){
                for(int i=result.size()-1;i>=0;i--)
                    cout<<result[i];
                cout<<endl;
                break;
            }
        }
        if(!findRe)cout<<-1<<endl;
    }

    return 0;
}