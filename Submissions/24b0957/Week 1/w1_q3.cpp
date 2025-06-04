// Url : https://codeforces.com/problemset/problem/1814/A

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    for(int i=0;i<t;i++){
        ll n,k;cin >>n>>k;
        if(n%2==0){cout << "YES"<<"\n";
            continue;
        }
        if(n<k && n%2!=0){
            cout << "NO"<<"\n";
            continue;
        }
        if(n==k){
            cout << "YES"<<"\n";
            continue;
        }
        if(n%2==1 && k%2==0){
            cout << "NO"<<"\n";
            continue;
        }
        if(n%2==1 && k%2==1){
            cout << "YES"<<"\n";
            continue;
        }
    }
    return 0;
}