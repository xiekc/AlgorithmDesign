#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

     
int main(){
	int k,n;
	string str,comp;
	map<char,char>m;
	m['A']='T';
	m['T']='A';
	m['G']='C';
	m['C']='G';
	
	cin>>k;
	while(k--){
		int result=0;
		multiset<string> s;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>str;
			comp="";
			for(int j=0;j<str.size();j++){
				comp+=m[str[j]];
			}
			if(s.find(comp)!=s.end()){
				s.erase(s.find(comp));
				result++;
			}
			else s.insert(str);
		}
		
		cout<<result<<endl;
	}
	
	return 0;
}