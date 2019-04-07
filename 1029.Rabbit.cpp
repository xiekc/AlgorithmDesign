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
BigInt operator +(const BigInt&a, const BigInt&b){
    BigInt one;
    int val=0,i;
    for(i=0;i<b.length||i<a.length||val;i++){
        if(i<a.length)val+=a.num[i];
        if(i<b.length)val+=b.num[i];
        one.num[i]=val%10;
        val/=10;
    }
    one.length=i;
    return one;
}

int main(){
    int m,d;
    BigInt arr[220];
    while(cin>>m>>d&&m!=0){
        arr[0]=1;
        for(int i=1;i<=d;i++){
            if(i-m<0)arr[i]=arr[i-1]+1;
            else arr[i]=arr[i-1]+arr[i-m];
        }
        for(int i=arr[d].length-1;i>=0;i--){
            cout<<arr[d].num[i];
        }
        cout<<endl;
    }
}