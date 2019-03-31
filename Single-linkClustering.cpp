#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Point{
	public:
		int x;
		int y;
};

class Edge{
	public:
		Edge(){
		}
		Edge(int a,int b,double length){
			this->a=a;
			this->b=b;
			this->length=length;
		}
		int a;
		int b;
		double length;
};

class EdgeCompare{
	public:
		bool operator()(Edge& a,Edge& b)const{
			return a.length>b.length;
		}
};

int findParent(vector<int>&parent,int i){
	return (parent[i]==-1)?i:parent[i]=findParent(parent,parent[i]);
}

void unionParent(vector<int>&parent,int a,int b){
	parent[a]=b;
}

int main(){
	int n,k;
	double x,y,distance;
	while(cin>>n>>k){
		priority_queue<Edge,vector<Edge>,EdgeCompare >q;
		vector<int>parent(n,-1);
		vector<Point>points;
		vector<Edge>edges;
		
		while(n--){
			Point p;
			cin>>p.x>>p.y;
			points.push_back(p);
        }

		for(int i=0;i<points.size();i++){
			for(int j=0;j<points.size();j++){
				if(j==i)continue;
				distance=sqrt(pow(points[i].x-points[j].x,2)+pow(points[i].y-points[j].y,2));
				q.push(Edge(i,j,distance));
			}
		}

		Edge t; 
        while(!q.empty()){
			t=q.top();q.pop();
            int x=findParent(parent,t.a),y=findParent(parent,t.b);
			if(x!=y){
				unionParent(parent,x,y);
				edges.push_back(t);
			}
		}

        printf("%.2f\n",edges[edges.size()-k+1].length);
	}
	
	return 0;
}
