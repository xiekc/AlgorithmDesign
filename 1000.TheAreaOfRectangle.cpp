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
        for(int i=0;i<n;i++){
            begin=end=i;
            while(begin>=0&&arr[begin]>=arr[i])begin--;
            while(end<n&&arr[end]>=arr[i])end++;
            maximum=max(maximum,arr[i]*(end-begin-1));
        }
        cout<<maximum<<endl;
    }
}