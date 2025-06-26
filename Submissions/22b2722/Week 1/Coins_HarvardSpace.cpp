#include <iostream>
using namespace std;

bool Coin(long long n, long long k) {
    if (k == 2) {
        return n % 2 == 0;
    }
    if (k % 2 == 0) {
        return n % 2 == 0;
    }    
    if (n % 2 == 0) {
        return true;
    }
    return n >= k;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        if (Coin(n, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}