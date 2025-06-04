#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long len=s.length();
    long rep;
    long Max=0;
    for(int i=0;i<len;i++){
        if(i==0){rep=1;Max=rep;}
        else{
            if(s[i]==s[i-1]){rep++;Max=max(Max,rep);}
            else{rep=1;}
        }
    }
    cout<<Max;
}