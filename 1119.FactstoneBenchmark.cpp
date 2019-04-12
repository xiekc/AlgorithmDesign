#include <iostream>
#include <cmath>
using namespace std;

int solve(int len){
    double re=0;
    for(int i=2;;i++){
        re+=log2(i);
        if(re>len)return i-1;
    }
}

int main(){
    int year,len;
    while(cin>>year&&year!=0){
        len=pow(2,(year-1960)/10+2);
        cout<<solve(len)<<endl;
    }

    return 0;
}