#include <bits/stdc++.h>
using namespace std;

using ll = long long;
string digits;
ll dp[20][11][2][2];

// pos: current position in digits
// prev: previous digit used (0-9), or 10 for "no previous digit"
// tight: 1 if prefix matches digits prefix exactly, else 0
// leading_zero: 1 if we have only placed zeros so far
ll dfs(int pos, int prev, bool tight, bool leading_zero) {
    if (pos == (int)digits.size()) return 1;

    if (dp[pos][prev][tight][leading_zero] != -1)
        return dp[pos][prev][tight][leading_zero];

    int limit = tight ? digits[pos] - '0' : 9;
    ll res = 0;
    for (int dig = 0; dig <= limit; dig++) {
        if (!leading_zero && dig == prev) continue; // no two adjacent digits equal

        bool next_tight = tight && (dig == limit);
        bool next_leading_zero = leading_zero && (dig == 0);

        res += dfs(pos + 1, next_leading_zero ? 10 : dig, next_tight, next_leading_zero);
    }

    return dp[pos][prev][tight][leading_zero] = res;
}

ll count_up_to(ll x) {
    if (x < 0) return 0;
    digits = to_string(x);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 10, true, true); // prev=10 means no prev digit
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    cout << count_up_to(b) - count_up_to(a - 1) << "\n";

    return 0;
}
