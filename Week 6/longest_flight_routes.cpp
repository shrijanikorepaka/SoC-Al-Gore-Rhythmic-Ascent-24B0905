#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> visited(N);
vector<int> topo;
int dp[N], parent[N];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
    topo.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build graph
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Topological sort using DFS
    dfs(1);
    reverse(topo.begin(), topo.end());

    // Initialize DP
    for (int i = 1; i <= n; i++) dp[i] = INT_MIN;
    dp[1] = 1; // Path of length 1 (just node 1)
    parent[1] = -1;

    for (int u : topo) {
        for (int v : adj[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dp[n] == INT_MIN) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct path
    vector<int> path;
    int cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (int node : path)
        cout << node << ' ';
    cout << '\n';

    return 0;
}
