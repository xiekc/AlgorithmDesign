#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

#define MAXN 60
ll arr[MAXN+1];
void getPal(){
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<MAXN;i++){
        if(i%2==1)arr[i]=2*arr[i-1];
        else arr[i]=arr[i-1];
    }
    ll sum=0;
    for(int i=1;i<MAXN;i++){
        sum+=arr[i];
        arr[i]=sum;
    }
}

int length(ll num){
    int len;
    for(len=0;num>0;len++){
        num=num>>1;
    }
    return len;
}

ll makePal(ll num,int len,bool odd){
    ll pal=num;
    if(odd){//odd extension
        for(int i=0;i<len-1;i++){
            if(num&(1<<i))pal+=1<<(2*len-i-2);
        }

    }else{//even extension
        for(int i=0;i<len;i++){
            if(num&(1<<i))pal+=1<<(2*len-i-1);
        }
        // cout<<pal<<endl;
    }

    return pal;
}

int main(){
    ll num,temp,len,ans;
    cin>>num;
    getPal();
    ans=0;
    len=length(num);
    bool odd=len%2;
    for(ll i=1;i<(1<<((len+1)/2));i+=2){
        temp=makePal(i,(len+1)/2,odd);
        if(temp<=num){
            ans++;
        }
    }
    ans+=arr[len-1];

    cout<<ans<<endl;
    return 0;
}