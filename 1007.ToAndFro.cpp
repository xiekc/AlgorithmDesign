#include <iostream>
#include <string>
using namespace std;

#define MAXN 22
char arr[MAXN][200];
int main(){
    int n;
    string s;
    while(cin>>n&&n!=0){
        cin>>s;
        for(int i=0;i<s.size();i++){
            if((i/n)%2==0)arr[i/n][i%n]=s[i];
            else arr[i/n][n-(i%n)-1]=s[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<s.size()/n;j++){
                cout<<arr[j][i];
            }
        }
        cout<<endl;
    }

    return 0;
}