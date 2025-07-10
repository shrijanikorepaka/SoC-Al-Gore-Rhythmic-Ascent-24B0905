#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int LOGK = 30; // since 2^30 > 1e9

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> next(n + 1, vector<int>(LOGK));
    for (int i = 1; i <= n; ++i) {
        cin >> next[i][0];
    }

    // Binary lifting table
    for (int j = 1; j < LOGK; ++j) {
        for (int i = 1; i <= n; ++i) {
            next[i][j] = next[next[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int x;
        long long k;
        cin >> x >> k;
        for (int j = 0; j < LOGK; ++j) {
            if (k & (1LL << j)) {
                x = next[x][j];
            }
        }
        cout << x << '\n';
    }

    return 0;
}
