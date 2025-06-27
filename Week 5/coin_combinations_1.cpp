#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int s = 1; s <= x; ++s) {
        for (int i = 0; i < n; ++i) {
            if (s >= coins[i]) {
                dp[s] = (dp[s] + dp[s - coins[i]]) % MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}
