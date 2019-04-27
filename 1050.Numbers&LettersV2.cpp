#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int t;

int solve(vector<ll>arr){
    ll ans=-0xffffff;
    vector<ll>front,temp;
    
    queue<vector<ll> >q;
    q.push(arr);
    while(!q.empty()){
        front=q.front();
        q.pop();

        for(int i=0;i<front.size();i++){
            if(front[i]>ans&&front[i]<=t){
                ans=front[i];
            }
            if(ans==t)return ans;
        }

        for(int i=0;i<front.size();i++){
            for(int j=i+1;j<front.size();j++){
                ll a=front[i],b=front[j];
                temp=front;
                temp.erase(temp.begin()+i);
                temp.erase(temp.begin()+j-1);
                
                temp.push_back(a+b);
                q.push(temp);
                temp.pop_back();

                temp.push_back(a-b);
                q.push(temp);
                temp.pop_back();

                temp.push_back(b-a);
                q.push(temp);
                temp.pop_back();

                temp.push_back(a*b);
                q.push(temp);
                temp.pop_back();

                if(b!=0&&a%b==0){
                    temp.push_back(a/b);
                    q.push(temp);
                    temp.pop_back();
                }
                if(a!=0&&b%a==0){
                    temp.push_back(b/a);
                    q.push(temp);
                    temp.pop_back();
                }
            }
        }
    }

    return ans;
}

int main(){
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<ll>arr;
        for(int j=0;j<5;j++){
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>t;
        cout<<solve(arr)<<endl;
    }
}