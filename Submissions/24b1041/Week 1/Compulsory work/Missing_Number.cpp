#include<bits/stdc++.h>
using namespace std;

int main(){
    long n;
    cin>>n;
    long sum;
    sum=(n*(n+1))/2;
    for(long i=1;i<n;i++){
        long x;
        cin>>x;
        sum-=x;
    }
    cout<<sum;
}