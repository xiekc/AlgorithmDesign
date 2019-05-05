#include <iostream>
#include <cstring>
using namespace std;
// the same apples and different baskets 
#define MAXN 101
long long apple,basket,result;
int arr[MAXN];
 
void backtrack(int cur,int total){
    if(total==apple){
        // for(int i=0;i<basket;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        result++;
        return;
    }
    for(int i=cur;i<basket;i++){
        // arr[i]++;
        backtrack(i,total+1);
        // arr[i]--;
    }
}

int main(){
    while(cin>>apple>>basket&&apple!=0){
        memset(arr,0,sizeof(arr));
        result=0;
        backtrack(0,0);
        cout<<result<<endl;
    }
    return 0;
}