#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char output[100][11];
int main(){
    string keyword,sentence;
    while(cin>>keyword&&keyword!="THEEND"){
        cin>>sentence;
        vector<pair<char,int> >v;
        for(int i=0;i<keyword.size();i++){
            v.push_back(make_pair(keyword[i],i));
        }
        sort(v.begin(),v.end());        

        for(int i=0,k=0;i<keyword.size();i++){
            for(int j=0;j<sentence.size()/keyword.size();j++,k++){
                output[j][v[i].second]=sentence[k];
            }
        }

        for(int i=0;i<sentence.size()/keyword.size();i++){
            for(int j=0;j<keyword.size();j++){
                cout<<output[i][j];
            }
        }
        cout<<endl;
    }

    return 0;
}