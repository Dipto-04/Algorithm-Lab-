#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long INF = 1e18;
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<pair<int,int>>> adj(nodes + 1);
    for (int i = 0; i < edges; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        adj[x].push_back({y, cost});
        adj[y].push_back({x, cost});
    }

    vector<long long> dist(nodes + 1, INF);
    vector<int> parent(nodes + 1, 0);
    dist[1] = 0;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            long long nd = du + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
                pq.push({nd, v});
            }
        }
    }

    if (dist[nodes] == INF) {
        cout << -1;
        return 0;
    }

    vector<int> route;
    for (int cur = nodes; cur != 0; cur = parent[cur]) route.push_back(cur);
    reverse(route.begin(), route.end());

    for (int v : route) cout << v << ' ';
    return 0;
}
