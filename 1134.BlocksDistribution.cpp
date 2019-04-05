#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<pair<int,int> >v;

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int main(){
    ll n,s;
    int a,b;
    while(cin>>n>>s&&n!=0){
        for(int i=0;i<n;i++){
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end(),cmp);

        while(!v.empty()){
            a=v[0].first;
            b=v[0].second;
            if(s<b)break;
            else {
                s+=a;
                v.erase(v.begin());
            }
        }
        cout<<(v.empty()?"YES":"NO")<<endl;
    }

    return 0;
}