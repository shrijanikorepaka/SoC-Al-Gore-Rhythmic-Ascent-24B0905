#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Store edges as vector of tuples: (from, to, cost)
    vector<tuple<int,int,long long>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges[i] = make_tuple(a, b, c);
    }

    vector<long long> dist(n+1, 0);
    vector<int> parent(n+1, -1);
    int x = -1;

    // Bellman-Ford
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < m; j++) {
            int a = get<0>(edges[j]);
            int b = get<1>(edges[j]);
            long long c = get<2>(edges[j]);
            if (dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // Go back n steps to ensure inside the cycle
        int y = x;
        for (int i = 0; i < n; i++) {
            y = parent[y];
        }

        // Reconstruct cycle
        vector<int> cycle;
        for (int cur = y;; cur = parent[cur]) {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        for (int node : cycle) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
