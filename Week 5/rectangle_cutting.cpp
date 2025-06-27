#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const int N = 500;
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            if (x == y) {
                dp[x][y] = 0;
            } else {
                int best = 1e9;
                // vertical cuts
                for (int k = 1; k < x; ++k) {
                    best = min(best, dp[k][y] + dp[x - k][y] + 1);
                }
                // horizontal cuts
                for (int k = 1; k < y; ++k) {
                    best = min(best, dp[x][k] + dp[x][y - k] + 1);
                }
                dp[x][y] = best;
            }
        }
    }

    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << endl;
    return 0;
}
