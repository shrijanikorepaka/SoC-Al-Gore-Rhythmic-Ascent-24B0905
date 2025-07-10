#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        edges.push_back({a, b, -x}); // negate weights
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int a = edges[j].u;
            int b = edges[j].v;
            ll x = edges[j].w;
            if (dist[a] != INF && dist[a] + x < dist[b]) {
                dist[b] = dist[a] + x;
            }
        }
    }

    // Mark nodes that can still be relaxed (i.e., affected by a positive cycle)
    vector<bool> affected(n + 1, false);
    for (int j = 0; j < m; ++j) {
        int a = edges[j].u;
        int b = edges[j].v;
        ll x = edges[j].w;
        if (dist[a] != INF && dist[a] + x < dist[b]) {
            affected[b] = true;
        }
    }

    // BFS from affected nodes
    vector<bool> visited(n + 1, false);
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (affected[i]) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    if (visited[n]) {
        cout << -1 << endl;
    } else {
        cout << -dist[n] << endl;  // negate back the result
    }

    return 0;
}
