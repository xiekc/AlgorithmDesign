#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

#define MAXN 1000010
vector<int>primes;
bool isPrime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)return false;
    }
    return true;
}
void getPrime(){
    for(int i=2;i<MAXN;i++){
        if(isPrime(i))primes.push_back(i);
    }
}

int mod(string num,int fac){
    int carry=0,curr;
    for(int i=0;i<num.size();i++){
        curr=carry*10+num[i]-'0';
        carry=curr%fac;
    }
    return carry;
}

int main(){
    getPrime();
    string key;
    int len,ans;
    while(cin>>key>>len&&len!=0){
        ans=0;
        for(int i=0;primes[i]<len;i++){

            if(mod(key,primes[i])==0){
                ans=primes[i];
                break;
            }
        }
        if(ans!=0){
            cout<<"BAD "<<ans<<endl;
        }else cout <<"GOOD\n";
    }

    return 0;
}