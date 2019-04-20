#include <iostream>
#include <string>
using namespace std;

int main(){
    int t,temp,carry;
    cin>>t;
    while(t--){
        string end,num(11,0);
        cin>>end;
        
        for(int i=0;i<end.size()/2;i++){
            swap(end[i],end[end.size()-1-i]);
        }

        // one-digit multiplication
        carry=0;
        for(int i=0;i<end.size();i++){
            // enumerate 0 ~ 9
            for(num[i]=0;num[i]<=9;num[i]++){
                temp=carry;    
                for(int a=0;a<=i;a++){
                    for(int b=0;a+b<=i;b++){
                        int c=i-a-b;
                        temp+=num[a]*num[b]*num[c];
                    }
                }

                if((temp%10)==(end[i]-'0'))break;
            }
            carry=temp/10;
        }

        while(num[num.size()-1]==0)num.pop_back();
        for(int i=num.size()-1;i>=0;i--){
            printf("%d",num[i]);
        }
        cout<<endl;
    }

    return 0;
}