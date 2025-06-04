#include<bits/stdc++.h>
using namespace std;

void func(int a, int b,int n,int c){
    if(n==1){cout<<a<<" "<<b<<endl;}
    else{
        func(a,c,n-1,b);
        cout<<a<<" "<<b<<endl;
        func(c,b,n-1,a);
    }
}
int main(){
    int n;
    cin>>n;
    long res;
    res=pow(2,n)-1;
    cout<<res<<endl;
    func(1,3,n,2);
}