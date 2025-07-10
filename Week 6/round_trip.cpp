#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int parent[MAXN], visited[MAXN];
int start = -1, endp = -1;

bool dfs(int node, int par) {
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (neighbor == par) continue;
        if (visited[neighbor]) {
            start = neighbor;
            endp = node;
            return true;
        }
        parent[neighbor] = node;
        if (dfs(neighbor, node)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // Undirected graph
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            parent[i] = -1;
            if (dfs(i, -1)) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = endp; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
