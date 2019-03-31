#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a,char b){
    return a>b;
}

int main(){
    string num;
    int t,start;
    cin>>t;
    while(t--){
        cin>>num;
        start=0;
        for(int i=0;i<=num.size();i++){
            if(num[i]=='0'||i==num.size()){
                sort(num.begin()+start,num.begin()+i,cmp);
                start=i+1;
            }
        }
        cout<<num<<endl;
    }

    return 0;
}