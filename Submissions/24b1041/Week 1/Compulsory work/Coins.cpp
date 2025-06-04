#include<iostream>
using namespace std;

int main(){
    long long N;
    cin>>N;
    for(long long i=1;i<=N;i++){
        long long n;
        cin>>n;
        long long k;
        cin>>k;
        if(k%2==0 && n%2!=0){cout<<"NO"<<endl;continue;}
        if(k==1 && n==1){cout<<"YES"<<endl;continue;}
        if(k>n || 2>n){cout<<"NO"<<endl; continue;}
        cout<<"YES"<<endl;
    }
}