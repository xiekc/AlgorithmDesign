#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int k;
    string ipStr,nameStr;
    while(cin>>k&&k!=0){
        map<string,string>ip,name;
        while(k--){
            cin>>nameStr>>ipStr;
            auto it=ip.find(ipStr);
            if(it==ip.end()){
                ip[ipStr]=nameStr;
                //or ip.insert(pair<string,string>(ipStr,nameStr));
            }else name[it->second]=nameStr;
        }

        for(auto it=name.begin();it!=name.end();it++){
           cout<<it->second<<" is the MaJia of "<<it->first<<endl;
        }
        cout<<endl;
    }
}
