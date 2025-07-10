#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; long long c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    // distances[node] stores up to k shortest distances to node, sorted ascending
    vector<vector<long long>> distances(n + 1);

    // Min-heap: (cost, node)
    priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        // If we already have k shortest distances and cost is greater than largest, skip
        if ((int)distances[node].size() == k && cost > distances[node].back())
            continue;

        // Insert cost in sorted order (k is small so linear insertion is fine)
        auto &distList = distances[node];
        if ((int)distList.size() < k) {
            distList.push_back(cost);
            sort(distList.begin(), distList.end());
        } else if (cost < distList.back()) {
            distList.pop_back();
            distList.push_back(cost);
            sort(distList.begin(), distList.end());
        } else {
            continue;
        }

        // Push neighbors with updated cost if it can improve neighbor's top k distances
        for (auto &e : graph[node]) {
            long long newCost = cost + e.cost;
            auto &nbrDist = distances[e.to];
            if ((int)nbrDist.size() < k || newCost < nbrDist.back()) {
                pq.push({newCost, e.to});
            }
        }
    }

    // Output the k shortest distances to node n
    for (auto x : distances[n]) cout << x << ' ';
    cout << '\n';

    return 0;
}
