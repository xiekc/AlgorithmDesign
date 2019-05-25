#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 110
int a[MAXN],b[MAXN];
bool flag[MAXN];
vector<int> offspring(int*a,int*b,int ri,int le,int n){
    vector<int> v(n,0);
    memset(flag,0,sizeof(flag));

    for(int j=le;j<=ri;j++){
        v[j]=a[j];
        flag[a[j]]=true;
    }
    for(int i=0,k=0;i<n;i++){
        if(!flag[b[i]]){
            if(k==le)k=ri+1;
            v[k]=b[i];
            k++;
        }
    }
    return v;
}

void output(vector<int>v){
    if(v.size())cout<<v[0];
    for(int i=1;i<v.size();i++){
        cout<<" "<<v[i];
    }
    cout<<endl;
}

int main(){
    int n,le,ri;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        cin>>le>>ri;
        output(offspring(a,b,ri,le,n));
        output(offspring(b,a,ri,le,n));        
    }

    return 0;
}