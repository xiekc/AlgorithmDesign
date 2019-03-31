#include <iostream>
#include <stack>
using namespace std;

int arr[200010];//not 100010,100000*2
int main(){
    int k,a,b;
    while(cin>>k&&k!=0){     
        stack<int>s;
        for(int i=0;i<k;i++){
            cin>>a>>b;
            arr[a]=arr[b]=i;
        }

        for(int i=1;i<=2*k;i++){
            if(!s.empty()&&s.top()==arr[i]){
                s.pop();
            }
            else {s.push(arr[i]);}
        }

        cout<<(s.empty()?"Yes":"No")<<endl;
    }

    return 0;
}
// line equals to circle