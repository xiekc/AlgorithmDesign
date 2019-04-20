#include <iostream>
#include <string>
using namespace std;

int main(){
    string str,num;
    while(cin>>str&&str!="0"){
        int sum=0,base=1;
        num=str;
        for(int i=num.size()-1;i>=0;i--){
            num[i]-='0';
            if(num[i]>4)num[i]--;
            sum+=num[i]*base;
            base*=9;
        }

        cout<<str<<": "<<sum<<endl;        
    }

    return 0;
}