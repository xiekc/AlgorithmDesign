#include <iostream>
#include <cstring>
using namespace std;

struct BigInt{
    int num[100],length;
    BigInt(int val=0){
        memset(num,0,sizeof(num));
        length=1;
        num[0]=val;
    }
    
};

BigInt operator * (const BigInt& a,const BigInt&b){
    BigInt big;
    int val=0;
    for(int i=0;i<a.length;i++){
        for(int j;j<b.length;j++){
            val=a.num[i]*b.num[j];
            big.num[i+j]+=val;
        }
    }
    for(int i=0;i<a.length+b.length;i++){
        
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){

    }
}