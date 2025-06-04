#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int luckiness(long x){
    string s=to_string(x);
    char max= *max_element(s.begin(),s.end());
    char min= *min_element(s.begin(),s.end());
    return max-min;
}
long luckiest(long x, long y){
    int Max=0;
    long result=0;
    for(long i=x;i<=y;i++){
        int c=luckiness(i);
        if(c>=Max){result=i;Max=c;}
        if(Max==9){break;}
    }
    return result;
}
int main(){
    long N;
    cin>>N;
    while(N--){
        long a,b;
        cin>>a>>b;
        long res=luckiest(a,b);
        cout<<res<<endl;
    }
}