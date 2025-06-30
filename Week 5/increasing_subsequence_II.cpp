#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Fenwick {
    vector<long long> fenw;
    int n;
    Fenwick(int n) : n(n) {
        fenw.assign(n + 1, 0);
    }
    void update(int i, long long v) {
        while (i <= n) {
            fenw[i] = (fenw[i] + v) % MOD;
            i += i & (-i);
        }
    }
    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum = (sum + fenw[i]) % MOD;
            i -= i & (-i);
        }
        return sum;
    }
    long long range_query(int l, int r) {
        return (query(r) - query(l - 1) + MOD) % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    // Coordinate compression
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

    auto compress = [&](int x) {
        return int(lower_bound(sorted_arr.begin(), sorted_arr.end(), x) - sorted_arr.begin()) + 1;
    };

    Fenwick fenw((int)sorted_arr.size());

    long long result = 0;
    for (int i = 0; i < n; i++) {
        int c = compress(arr[i]);
        // number of increasing subsequences ending at i:
        // 1 (single element) + sum of dp for smaller elements
        long long dp_i = (1 + fenw.query(c - 1)) % MOD;
        fenw.update(c, dp_i);
        result = (result + dp_i) % MOD;
    }

    cout << result << "\n";
    return 0;
}
