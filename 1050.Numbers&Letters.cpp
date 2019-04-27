#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int t;
ll ans;
void solve(vector<ll>arr){
    // cout<<1<<endl;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>ans&&arr[i]<=t){
            ans=arr[i];
        }
        if(ans==t)return;
    }

    vector<ll>temp;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            ll a=arr[i],b=arr[j];
            temp=arr;
            temp.erase(temp.begin()+i);
            temp.erase(temp.begin()+j-1);
            
            temp.push_back(a+b);
            solve(temp);
            temp.pop_back();

            temp.push_back(a-b);
            solve(temp);
            temp.pop_back();

            temp.push_back(b-a);
            solve(temp);
            temp.pop_back();

            temp.push_back(a*b);
            solve(temp);
            temp.pop_back();

            if(b!=0&&a%b==0){
                temp.push_back(a/b);
                solve(temp);
                temp.pop_back();
            }
            if(a!=0&&b%a==0){
                temp.push_back(b/a);
                solve(temp);
                temp.pop_back();
            }
        }
    }
}

int main(){
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<ll>arr;
        ans=-0xffffff;
        for(int j=0;j<5;j++){
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>t;
        solve(arr);
        cout<<ans<<endl;
    }
}