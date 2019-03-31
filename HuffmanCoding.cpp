#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
	int n,f,result=0,a,b;
	cin>>n;
	
	string s;
	priority_queue<int,vector<int>,greater<int> >q;
	if(n==1)q.push(0);
	while(n--){
		cin>>s>>f;
		q.push(f);
	}
	
	while(q.size()>1){
		a=q.top();q.pop();
		b=q.top();q.pop();
		result+=a+b;
		q.push(a+b);
	}
	
	cout<<result<<endl;
	
	return 0;
}
