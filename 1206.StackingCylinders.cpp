#include <iostream>
#include <complex>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

typedef complex<double> Point;
bool cmp(const Point&a,const Point&b){
    return a.real()<b.real();
}

int main(){
    int n,count=1;
    Point arr[12][12],temp;
    int t;
    double te;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>te;
            arr[0][i]=Point(te,1);
        }
        sort(*arr,*arr+n,cmp);

        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                temp=(arr[i-1][j+1]-arr[i-1][j]);
                double len=sqrt(norm(temp));//sqrt!!!
                double midLen=sqrt(4-len*len/4);
                double s=(arr[i-1][j+1].imag()-arr[i-1][j].imag())/len;
                double c=(arr[i-1][j+1].real()-arr[i-1][j].real())/len; 
                arr[i][j]=arr[i-1][j]+temp*Point(0.5,0)+midLen*Point(-s,c);
            }
        }
        cout<<count<<": ";
        cout<<setiosflags(ios::fixed)<<setprecision(4)<<arr[n-1][0].real()<<" "<<arr[n-1][0].imag()<<endl;
        // printf("%.4f %.4f\n",arr[n-1][0].real(),arr[n-1][0].imag());
        count++;
    }
}