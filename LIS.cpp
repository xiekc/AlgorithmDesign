#include <iostream>
using namespace std;

int main(){
    int arr[6000],len[6000],par[6000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        len[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<=arr[i]&&len[j]+1>len[i]){
                len[i]=len[j]+1;
                par[i]=j;
            }
        }
    }

    int maxI=0;
    for(int i=0;i<n;i++){
        if(len[maxI]<len[i]||(len[maxI]==len[i]&&arr[maxI]>arr[i])){
            maxI=i;
        }
    }
    cout<<len[maxI]<<" "<<arr[maxI]<<endl;

    return 0;
}