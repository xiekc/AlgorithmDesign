#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
const ll mod=1000000000+7;
// const ll mod=10000;

class Matrix{
	public:
		ll arr[2][2];
		Matrix (){
			memset(arr,0,sizeof(arr));
		}

		Matrix (int p){
			if(p==1){
				arr[0][0]=1,arr[0][1]=1,arr[1][0]=1,arr[1][1]=0;
			}
		}
		
		Matrix operator *(const Matrix& other){
			Matrix m;
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					for(int k=0;k<2;k++){
						m.arr[i][j]=(m.arr[i][j]+this->arr[i][k]*other.arr[k][j])%mod;
					}
				}
			}
			
			return m;
		}

		Matrix& operator =(const Matrix& m){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					this->arr[i][j]=m.arr[i][j];
				}
			}
			return *this;
		}

		void print(){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					cout<<this->arr[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

Matrix fib(ll n){
	Matrix m(1);
	Matrix base(1);
	
	while(n){
		if(n&1)m=(m*base);
		base=(base*base);
		n>>=1;
	}
	return m;
}

int main(){
	ll n;
	while(cin>>n){
		Matrix m=fib(n);
		cout<<m.arr[1][1]<<endl;
	}
	return 0;
}
