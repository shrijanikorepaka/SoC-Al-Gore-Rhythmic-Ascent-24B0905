// url : https://cses.fi/problemset/task/1069

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
    string s;
    cin >> s;
    ll max=0,temp=0;
    char current = s[0];
    for(size_t i=0;i<s.length();i++){
        if(s[i]==current){
            temp++;
        }
        else{
            current = s[i];
            temp = 1;
        }
        if(temp>max){
            max = temp;
        }
    }
    cout << max << "\n";
    return 0;
}