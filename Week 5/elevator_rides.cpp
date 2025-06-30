#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n; 
    long long x;
    cin >> n >> x;
    vector<long long> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    // dp[mask] = pair<rides, leftover>
    // rides = minimum number of rides needed to carry people in subset mask
    // leftover = weight used in the last ride
    vector<pair<int, long long>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0}; // no people => 1 ride with 0 weight used

    for (int mask = 0; mask < (1 << n); mask++) {
        int rides = dp[mask].first;
        long long leftover = dp[mask].second;

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                long long w_i = w[i];
                int new_rides;
                long long new_leftover;

                if (leftover + w_i <= x) {
                    // add person i to current ride
                    new_rides = rides;
                    new_leftover = leftover + w_i;
                } else {
                    // start a new ride for person i
                    new_rides = rides + 1;
                    new_leftover = w_i;
                }

                int new_mask = mask | (1 << i);
                // minimize rides, then leftover weight
                if (make_pair(new_rides, new_leftover) < dp[new_mask]) {
                    dp[new_mask] = {new_rides, new_leftover};
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].first << "\n";

    return 0;
}
