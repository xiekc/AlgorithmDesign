#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
vector<int>primes;
void getPrimes(){
    bool arr[65];
    memset(arr,0,sizeof(arr));
    for(int i=2;i<64;i++){
        if(arr[i])continue;
        primes.push_back(i);
        for(int j=2;i*j<64;j++){
            arr[i*j]=true;
        }
    }
}

int main(){
    getPrimes();
    int t;
    cin>>t;
    t=min(t,59);
    for(int k=0;primes[k]<=t;k++){
        int n=primes[k];
        ll num=((ll)1<<n)-1,temp=num;
        vector<ll> re;
        for(ll i=2;i*i<num;i++){
            while(num%i==0){
                re.push_back(i);
                num/=i;
            }
        }
        if(num!=0)re.push_back(num);

        if(re.size()>1){
            for(int i=0;i<re.size()-1;i++){
                cout<<re[i]<<" * ";
            }
            cout<<re[re.size()-1]<<" = "<<temp<<" = ( 2 ^ "<<n<<" ) - 1\n";
        }
    }
    return 0;
}