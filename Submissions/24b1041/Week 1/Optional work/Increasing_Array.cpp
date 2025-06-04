#include<bits/stdc++.h>
using namespace std;

int main(){
    long N;
    cin>>N;
    bool hey=true;
    long long prevx;
    long long wan=0;
    while(N--){
        long long newx;
        cin>>newx;
        if(hey){prevx=newx;hey=false;continue;}
        if(prevx>newx){
            int diff=prevx-newx;
            wan +=diff;
            prevx=max(prevx,newx);
        }
        prevx=max(prevx,newx);
    }
    cout<<wan;
}