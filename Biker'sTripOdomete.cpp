#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	const double pi=3.1415927;
	double di,time,distance;
	int re,count=0;
	while(cin>>di>>re>>time&&re!=0){
		count++;
		cout<<"Trip #"<<count<<": ";
		distance=pi*di*re/12/5280;
		cout<<setiosflags(ios::fixed)<<setprecision(2);
		cout<<distance<<" ";
		cout<<distance/(time/3600)<<endl;
	}
	
	return 0;
}