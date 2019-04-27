#include <iostream>
#include <cstring>
using namespace std;

// top down
int dpArr[1010][1010];
bool dpCall[1010][1010];
int n,arr[1010];
int dp(int l,int r){
    if(l>r)return 0;
    if(dpCall[l][r])return dpArr[l][r];
    dpCall[l][r]=true;
    // two choices: selecting left or right
    // distinguish 1 and l !!!
    dpArr[l][r]=max(((arr[l+1]>=arr[r])?(dp(l+2,r)+arr[l]-arr[l+1]):(dp(l+1,r-1)+arr[l]-arr[r])),
        ((arr[l]>=arr[r-1])?(dp(l+1,r-1)+arr[r]-arr[l]):(dp(l,r-2)+arr[r]-arr[r-1])));
    return dpArr[l][r];
}


int main(){
    int count=0;
    while(cin>>n&&n!=0){
        count++;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        //can not use 0 or -1 to fill dpArr to judge whether has called!!! 
        memset(dpCall,false,sizeof(dpCall));
        memset(dpArr,0,sizeof(dpArr));

        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",count,dp(0,n-1));
    }

    return 0;
}