#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;

int n, m;
int full_mask;

vector<vector<int>> transitions;

// Generate all possible masks for next column given current column mask
void dfs(int pos, int cur_mask, int next_mask, vector<int> &trans) {
    if (pos == n) {
        if (cur_mask == full_mask) {
            trans.push_back(next_mask);
        }
        return;
    }
    if ((cur_mask & (1 << pos)) != 0) {
        // Current cell already filled, go next
        dfs(pos + 1, cur_mask, next_mask, trans);
    } else {
        // Place vertical domino covering pos and pos+1 in current column
        if (pos + 1 < n && ((cur_mask & (1 << (pos + 1))) == 0)) {
            dfs(pos + 2, cur_mask | (1 << pos) | (1 << (pos + 1)), next_mask, trans);
        }
        // Place horizontal domino covering pos in current and pos in next column
        dfs(pos + 1, cur_mask | (1 << pos), next_mask | (1 << pos), trans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    full_mask = (1 << n) - 1;

    transitions.resize(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> trans;
        dfs(0, mask, 0, trans);
        transitions[mask] = move(trans);
    }

    // dp[mask]: number of ways to fill columns processed so far
    // mask = which cells are filled in current column (before placement)
    vector<int> dp(1 << n, 0);
    dp[0] = 1; // start with empty column

    for (int col = 0; col < m; col++) {
        vector<int> new_dp(1 << n, 0);
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == 0) continue;
            for (int nxt : transitions[mask]) {
                new_dp[nxt] = (new_dp[nxt] + dp[mask]) % MOD;
            }
        }
        dp = move(new_dp);
    }

    // After last column, column must be fully covered => dp[0]
    cout << dp[0] << "\n";

    return 0;
}
