#include<bits/stdc++.h>
using namespace std;

bool check(long long a,long long b){
    return (a+b)%3==0 && max(a,b)<=2*min(a,b);
}
int main(){
    long N;
    cin>>N;
    while(N--){
        long long a,b;
        cin>>a>>b;
        bool res=check(a,b);
        if(res){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
}