#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

#define MAX pow(10,8)
// AC
float dp[1<<20][20];
queue<int>q;
int main(){
	int t;
	float arr[22][2],dis[22][22];
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// n=20;
		for(int i=0;i<n;i++){
			// arr[i][0]=arr[i][1]=i;
			cin>>arr[i][0]>>arr[i][1];
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				dis[i][j]=dis[j][i]=sqrt(pow(arr[i][0]-arr[j][0],2)+pow(arr[i][1]-arr[j][1],2));
				// cout<<i<<"-"<<j<<" "<<dis[i][j]<<endl;
			}
		}
		for(int i=0;i<(1<<(n));i++){
			for(int j=0;j<n;j++){
				dp[i][j]=MAX;
			}
		}
		
		dp[1][0]=0;

		q.push(1);
		while(!q.empty()){
			int s=q.front();q.pop();
			for(int i=1;i<n;i++){
				if(dp[s][i]!=MAX)break;
				if(!(s&(1<<i))){
					q.push(s+(1<<i));
				}
			}
			
			for(int i=1;i<n;i++){
				if(dp[s][i]!=MAX)break;
				if(s&(1<<i)){//i in set
					for(int j=0;j<n;j++){
						if((s&(1<<j))&&(j!=i)){//j in set
							dp[s][i]=min(dp[s-(1<<i)][j]+dis[i][j],dp[s][i]);
						}
					}
				}
			}
		}

		// float ans=MAX;
		// for(int i=1;i<n;i++){
		// 	ans=min(dp[(1<<(n))-1][i]+dis[0][i],ans);
		// }
		printf("%.2f\n",dp[(1<<n)-1][n-1]);
	}
	
	return 0;
}
