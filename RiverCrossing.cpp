#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 0x7ffff

int dp[100*200];
bool isStone[100*200];
int main(){
    int len,minL,maxL,n,stone[110];
    int result;
    cin>>len;
    cin>>minL>>maxL>>n;
    for(int i=0;i<n;i++){
        cin>>stone[i];
    }

    if(minL==maxL){
        result=0;
        for(int i=0;i<n;i++){
            if(stone[i]%minL==0){
                result++;
            }
        }
    }else{
        sort(stone,stone+n);
        memset(isStone,false,sizeof(isStone));

        //preprocess
        //relative location is unchanged!!!
        int total=0;
        for(int i=0,prev=0;i<n;i++){
            total+=min(stone[i]-prev,100);
            isStone[total]=true;
            prev=stone[i];
        }

        len=total+100;
        for(int i=0;i<=len;i++){
            dp[i]=MAX;
        }
        dp[0]=0;

        for(int i=1;i<=len;i++){
            for(int j=minL;(j<=maxL)&&(i-j>=0);j++){
                dp[i]=min(dp[i],dp[i-j]);
            }
            if(isStone[i]) dp[i]++;
        }

        result=MAX;
        for(int i=len-100+1;i<=len;i++){
            result=min(result,dp[i]);
        }
    
    }
    cout<<result<<endl;

    return 0;
}