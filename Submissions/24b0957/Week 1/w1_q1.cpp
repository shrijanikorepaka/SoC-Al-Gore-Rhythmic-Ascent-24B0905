// url : https://cses.fi/problemset/task/1083

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
    int n;
    cin >>n;
    int a[n-1];
    for(int i=0;i<n-1;i++){
        cin >> a[i];

    }
    sort(a, a+(n-1));
    int i;
    for(i=0;i<n-1;i++){
        if(a[i]+a[n-1-i-1]!=n+1){
            break;
        }
    }
    if(a[i]!=i+1){
        cout << i+1 << "\n";
    }
    else {cout << n-i<<"\n";}

    return 0;
}