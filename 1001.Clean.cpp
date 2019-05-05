#include <iostream>
using namespace std;

#define MAXN 1010
int arr[MAXN];
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int result=0;
        bool ok=true,start=false;
        while(true){
            ok=true;
            start=false;
            for(int i=0;i<n;i++){
                if(arr[i]!=0){
                    start=true;
                    ok=false;
                    arr[i]--;
                }else if(start==true){
                    // cout<<i<<" ";
                    result++;
                    start=false;
                }
            }
            if(start==true)result++;
            if(ok)break;
        }
        cout<<result<<endl;
    }
}