#include<iostream>
using namespace std;

int main(){
    long N;
    cin>>N;
    while(N--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(c-a>d-b){cout<<-1<<endl;}
        else if(d<b){cout<<-1<<endl;}
        else if((c-a)==(d-b)){cout<<abs(c-a)<<endl;}
        else{cout<<2*(d-b)-(c-a)<<endl;}
    }
    return 0;
}