#include <iostream>
#include <cstring>
using namespace std;
// the same apples and the same baskets 
#define MAXN 101
long long apple,basket,result;
 
int recursion(int apple,int basket){

}

int arr[MAXN][MAXN];
int dp(int apple,int basket){
    memset(arr,0,sizeof(arr));
    for(int i=0;i<=apple;i++){
        arr[i][1]=1;
    }
    for(int j=0;j<=basket;j++){
        arr[0][j]=1;
    }
    for(int i=1;i<=apple;i++){
        for(int j=1;j<=basket;j++){
            if(j>i)arr[i][j]=arr[i][i];
            else arr[i][j]=arr[i][j-1]+arr[i-j][j];
        }
    }
    return arr[apple][basket];
}

int main(){
    while(cin>>apple>>basket&&apple!=0){
        
        cout<<dp(apple,basket)<<endl;
    }
    return 0;
}