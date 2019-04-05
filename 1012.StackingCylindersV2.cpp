#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point{
    Point(double x=0,double y=0):x(x),y(y){}
    double x,y;
    Point operator +(const Point& p){
        return Point(x+p.x,y+p.y);
    }
    Point operator -(const Point& p){
        return Point(x-p.x,y-p.y);
    }
    Point operator *(double d){
        return Point(d*(x),d*(y));
    }
};

bool cmp(const Point &a,const Point&b){
    return a.x<b.x;
}

int main(){
    int n;
    Point arr[12][12],temp;
    double t;
    while(cin>>n&&n!=0){
        for(int i=0;i<n;i++){
            cin>>arr[0][i].x;
            arr[0][i].y=1;
        }
        sort(*arr,*arr+n,cmp);

        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                temp=(arr[i-1][j+1]-arr[i-1][j]);
                double len=sqrt(pow(temp.x,2)+pow(temp.y,2));
                double midLen=sqrt(4-len*len/4);
                double s=(arr[i-1][j+1].y-arr[i-1][j].y)/len;
                double c=(arr[i-1][j+1].x-arr[i-1][j].x)/len;
                arr[i][j]=arr[i-1][j]+temp*(0.5)+Point(-s,c)*midLen;
            }
        }
        printf("%.4f %.4f\n",arr[n-1][0].x,arr[n-1][0].y);
    }
}

// 1/2==0 !!!