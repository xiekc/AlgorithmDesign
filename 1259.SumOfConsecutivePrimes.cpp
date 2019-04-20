#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n<=1)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    int num,result,sum;
    vector<int>primes;
    sum=0;
    primes.push_back(0);
    for(int i=2;i<=10010;i++){
        if(isPrime(i)){
            sum+=i;
            primes.push_back(sum);
        }
    }

    while(cin>>num&&num!=0){
        result=0;
        for(int i=0;i<primes.size();i++){
            for(int j=i+1;j<primes.size();j++){
                if(primes[j]-primes[i]==num)result++;
            }
        }

        cout<<result<<endl;
    }

    return 0;
}