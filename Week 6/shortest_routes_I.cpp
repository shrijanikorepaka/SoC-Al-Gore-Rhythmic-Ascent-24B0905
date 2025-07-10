#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(make_pair(0, 1)); // (distance, node)

    while (!pq.empty()) {
        pair<ll, int> top = pq.top();
        pq.pop();
        ll d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int cost = adj[u][i].second;

            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
