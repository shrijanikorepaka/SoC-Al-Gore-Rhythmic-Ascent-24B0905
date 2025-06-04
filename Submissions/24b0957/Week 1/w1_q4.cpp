// url : https://codeforces.com/problemset/problem/1808/A

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll lucky(ll n){
    ll max_digit=0,min_digit=9;
    while(n>0){
        ll digit = n%10;
        max_digit = max(max_digit,digit);
        min_digit = min(min_digit,digit);
        n /= 10;
    }
    return max_digit - min_digit;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        ll a,b;
        cin >>a>>b;
        ll max=lucky(a);
        ll required=a;
        for(ll j=a+1;j<=min(b,a+100);j++){
            if(max<lucky(j)){
                max = lucky(j);
                required = j;
            }
	    if(max == 9) {break; }
        }
        cout << required << "\n";
    }

    return 0;
}
