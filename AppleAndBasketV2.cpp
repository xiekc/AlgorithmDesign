#include <iostream>
#include <cstring>
using namespace std;
 
#define MAXN 101
long long apple,basket,result;
int arr[MAXN];
// composition number: C(apple+basket-1,basket-1)
void backtrack(int cur,int total){
    if(total==apple){
        
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