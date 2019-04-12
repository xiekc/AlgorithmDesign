#include <iostream>
using namespace std;

typedef long long ll;

void solve(ll num,ll passA,ll passB,ll&numA,ll&numB){
    if(passA==0){
        if(passB==0)return;
        if(num%passB==0){
            numA=0;
            numB=num/passB;
        }
        return;
    }
    if(passB==0){
        if(num%passA==0){
            numA=num/passA;
            numB=0;
        }
        return;
    }
    for(int i=num/passA;i>=0;i--){
        if((num-i*passA)%passB==0){
            numA=i;
            numB=(num-i*passA)/passB;
            return;
        }
    }
            
}


int main(){
    int count=1;
    ll num,costA,passA,costB,passB,numA,numB;
    while(cin>>num&&num!=0){
        numA=numB=-1;
        cin>>costA>>passA>>costB>>passB;
        // double meanA=(double)costA/passA;
        // double meanB=(double)costB/passB;
        if(costA*passB<=costB*passA){
            solve(num,passA,passB,numA,numB);
        }else solve(num,passB,passA,numB,numA);

        if(numA==-1||numB==-1){printf("Data set %d: cannot be flown\n",count);}
        else printf("Data set %d: %lld aircraft A, %lld aircraft B\n",count,numA,numB);
        count++;
    }

    return 0;
}