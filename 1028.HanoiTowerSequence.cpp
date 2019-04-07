#include <iostream>
#include <string>
using namespace std;

bool modEqual0(string& num){
    int cur,pre=0;

    // s/2
    for(int i=0;i<num.size();i++){
        cur=pre*10+num[i];
        pre=cur%2;
        num[i]=cur/2;
    }

    return pre==0;
}

int main(){
    int count=1,t;
    string num;
    cin>>t;
    while(t--){
        cin>>num;
        for(int i=0;i<num.size();i++){
            num[i]-='0';
        }
        int r=1;
        while(modEqual0(num))r++;
        cout<<"Case "<<count<<": "<<r<<endl;//错在多了个:
        if(t!=0)cout<<endl;
        count++;
    }

    return 0;
}