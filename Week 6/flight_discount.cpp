#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e15;

struct Edge {
    int to;
    ll cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0;

    typedef tuple<ll, int, int> T; // (cost, node, used_coupon)
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push(make_tuple(0LL, 1, 0));

    while (!pq.empty()) {
        T top = pq.top();
        pq.pop();
        ll cost = get<0>(top);
        int u = get<1>(top);
        int used = get<2>(top);

        if (dist[u][used] < cost) continue;

        for (size_t i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            ll c = graph[u][i].cost;

            if (used == 0) {
                if (dist[v][0] > cost + c) {
                    dist[v][0] = cost + c;
                    pq.push(make_tuple(dist[v][0], v, 0));
                }
                ll discounted = cost + (c / 2);
                if (dist[v][1] > discounted) {
                    dist[v][1] = discounted;
                    pq.push(make_tuple(dist[v][1], v, 1));
                }
            }

            if (used == 1) {
                if (dist[v][1] > cost + c) {
                    dist[v][1] = cost + c;
                    pq.push(make_tuple(dist[v][1], v, 1));
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << '\n';
    return 0;
}
