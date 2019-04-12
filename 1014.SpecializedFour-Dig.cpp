#include <iostream>
using namespace std;

bool isSpecial(int num){
    int sum10=0,sum16=0,sum12=0,temp=num;
    while(temp){
        sum10+=temp%10;
        temp/=10;
    }

    temp=num;
    while(temp){
        sum16+=temp%16;
        temp/=16;
    }

    temp=num;
    while(temp){
        sum12+=temp%12;
        temp/=12;
    }
    return sum10==sum16&&sum10==sum12;
}

int main(){
    for(int i=1000;i<10000;i++){
        if(isSpecial(i))cout<<i<<endl;
    }

    return 0;
}