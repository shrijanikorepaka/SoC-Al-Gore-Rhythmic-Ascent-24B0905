#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN+1];
int team[MAXN+1]; // 0 = unvisited, 1 or 2 = team number

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (team[v] == 0) {
                team[v] = 3 - team[u]; // alternate team
                q.push(v);
            } else if (team[v] == team[u]) {
                return false; // conflict found
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        if (team[i] == 0) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << team[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
