#include <iostream>
#include <string>
using namespace std;

int getRemainder(const char* n,int d){
	int remainder=0;
	while(*n){
		remainder=(remainder*10+(*n-'0'))%d;
		n++;
	}
	return remainder;
}

int main(){
	int k,n,arr[200],d;
	string num;
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cin>>num;
		cout<<"(";
		for(int i=0;i<n;i++){
			cout<<getRemainder(num.c_str(),arr[i]);
			cout<<(i==n-1?')':',');
		}
		cout<<endl;
		
	}
	
	return 0;
}