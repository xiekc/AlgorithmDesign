#include <iostream>
#include <string>
using namespace std;
// the number of palindromes smaller than num

typedef long long ll;
ll arr[64]; 
int main(){
    ll num;
    arr[0]=1;
    for(int i=1;i<64;i++){
        if(i%2==1)arr[i]=arr[i-1]+arr[i-1];
        else arr[i]=2*arr[i-1]+arr[i-1];
    }
    // for(int i=0;i<10;i++)cout<<arr[i]<<" ";

    while(cin>>num){
        int length=0;
        while((1ll<<length)<=num)length++;
        ll result=1;
        for(int i=length;i>=0;i--){
            if((num&(1ll<<(i-1)))&&(i>length/2)){
                result+=arr[i-1];
            }else if((num&(1ll<<(i-1)))&&(i>length/2)){
                result+=1;
                break;
            }
        }    

        cout<<endl<<result<<endl;
    }

  return 0;
}