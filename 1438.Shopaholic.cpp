#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int t,n,arr[20010],discount;
    cin>>t;
    while(t--){
        cin>>n;
        discount=0;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++){
            if((i+1)%3==0)
                discount+=arr[i];
        }
        cout<<discount<<endl;
    }

    return 0;
}