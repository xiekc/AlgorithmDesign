#include <iostream>
using namespace std;

#define MAXN 1010
int arr[MAXN];
int main(){
    int t,n,begin,end;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maximum=0;
        int le=0,ri=n-1;
        while(le<ri){
            maximum=max(maximum,(ri-le)*min(arr[ri],arr[le]));
            if(arr[le]<=arr[ri])le++;
            else ri--;
        }
        cout<<maximum<<endl;
    }
}