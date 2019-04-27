#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int distan(string a,string b){
    int pos[200],re=0;
    for(int i=0;i<b.size();i++){
        pos[b[i]]=i;
    }

    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(pos[a[i]]>pos[a[j]])re++;
        }
    }
    return re;
}

int main(){
    int n;
    string s;
    while(cin>>n&&n!=0){
        string init="ABCDE",result;
        vector<string>v;
        int total=0,minDis=INT_MAX;
        
        for(int i=0;i<n;i++){
            cin>>s;
            v.push_back(s);
        }

        do{
            total=0;
            for(int i=0;i<n;i++){
                total+=distan(init,v[i]);
            }
            if(total<minDis){
                minDis=total;
                result=init;
            }
        }while(next_permutation(init.begin(),init.end()));
        printf("%s is the median ranking with value %d.\n",result.c_str(),minDis);
    }

    return 0;
}