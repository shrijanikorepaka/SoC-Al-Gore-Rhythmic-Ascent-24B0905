#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
        cin >> n >> k;

        int rem = n % k;

        if (rem % 2 == 0 ){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
	}
	return 0;
}