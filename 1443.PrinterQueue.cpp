#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t,n,m;
    int temp,result;
    cin>>t;
    while(t--){
        cin>>n>>m;
        priority_queue<int>pq;
        queue<pair<int,int> >qu;
        for(int i=0;i<n;i++){
            cin>>temp;
            pq.push(temp);
            qu.push(make_pair(temp,i));
        }

        result=0;
        while(!qu.empty()){
            pair<int,int>p=qu.front();
            while(p.first!=pq.top()){
                qu.push(p);
                qu.pop();
                p=qu.front();
            }
            pq.pop();
            qu.pop();
            result++;
            
            // cout<<"find:"<<p.first<<" "<<p.second<<endl;
            if(p.second==m){
                cout<<result<<endl;
                break;
            }
        }
    }

    return 0;
}