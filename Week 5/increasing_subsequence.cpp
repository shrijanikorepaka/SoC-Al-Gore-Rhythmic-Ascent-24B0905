#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<int> dp;
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), x[i]);
        if(it == dp.end()) {
            dp.push_back(x[i]);
        } else {
            *it = x[i];
        }
    }

    cout << dp.size() << "\n";
    return 0;
}
