#include <iostream>
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
    int num,start,end;
    while(cin>>num&&num!=0){
        start=end=num;
        while(true){
            if(isPrime(start))break;
            start--;
        }
        while(true){
            if(isPrime(end))break;
            end++;
        }

        cout<<end-start<<endl;
    }

    return 0;
}