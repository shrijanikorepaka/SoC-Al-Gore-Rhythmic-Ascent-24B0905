// url : https://cses.fi/problemset/task/1068

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
    ll n; cin >>n;
    cout << n << " ";
    while(n !=1){
        if(n%2 == 0){n=n/2;}
        else{n = 3*n + 1;}
        cout << n << " ";
    }
    cout << "\n";

    return 0;
}