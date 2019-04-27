#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a,string b){
	return a+b<b+a;
}

int main(){
	int k,n,arr[200],d;
	string str[10];
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>str[i];
		}
		
		sort(str,str+n,cmp);
		
		for(int i=0;i<n;i++){
			cout<<str[i];
		}
		cout<<endl;
	}
	
	return 0;
}