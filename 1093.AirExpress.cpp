#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

class time{
public:
	int start;
	int end;
};
     
int main(){
	int weight[4],price[4],n,count=0;
	while(cin>>weight[0]){
		cin>>price[0];
		cin>>weight[1]>>price[1];
		cin>>weight[2]>>price[2];
		cin>>price[3];
		
		count++;
		cout<<"Set number "<<count<<":\n";
		while(cin>>n&&n!=0){
			int k,cost,min;
			for(int i=0;i<4;i++){
				if(n<=weight[i]||i==3){
					k=i;
					break;	
				}
			}
			cost=n*price[k];
			min=k;
			for(int i=k+1;i<4;i++){
				if(price[i]*(weight[i-1]+1)<cost){
					cost=price[i]*(weight[i-1]+1);
					min=i;
				}
			}
			
			cout<<"Weight ("<<n<<") has best price $"<<cost<<" (add ";
			if(min==k){
				cout<<0;
			}else cout<<(weight[min-1]+1-n);
			cout<<" pounds)"<<endl;
		}

		cout<<endl;
	}
	
	
	return 0;
}
