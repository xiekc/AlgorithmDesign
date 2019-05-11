#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v[6]={1,5,10,25,50,100};
int w[6]={3,5,2,6,11,8};
int dp[10010];
int main(){
    int total,num[6];
    while(cin>>total){
        for(int i=0;i<6;i++){
            cin>>num[i];
        }

        vector<int>value;
        vector<int>weight;
        // 16=1+2+4+8  +1
        for(int i=0;i<6;i++){
            for(int j=1;j<=num[i];j*=2){
                if(num[i]>=j){
                    num[i]-=j;
                    value.push_back(j*v[i]);
                    weight.push_back(j*w[i]);
                }
            }
            value.push_back(num[i]*v[i]);//remained
            weight.push_back(num[i]*w[i]);
        }

        memset(dp,0,sizeof(dp));
        for(int i=0;i<value.size();i++){
            for(int j=total;j>=weight[i];j--){
                dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }

        printf("$%.2f\n",dp[total]/100.0);
    }


    return 0;
}