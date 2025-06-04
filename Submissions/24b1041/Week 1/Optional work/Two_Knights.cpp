#include<bits/stdc++.h>
using namespace std;

int main(){
    long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1){cout<<0<<endl;}
        else if(i==2){cout<<6<<endl;}
        else{
            long x;
            long long res;
            x=i*i;
            res=x*(x-1)/2-4*(i-1)*(i-2);
            cout<<res<<endl;
        }
    }
}