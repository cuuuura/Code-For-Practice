#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll INF = 4e18;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, ll>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
 
    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;
 
    dist[1] = 0;
    pq.push({0, 1});
 
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
 
        if (d != dist[u]) continue;
 
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
 
    if (dist[n] == INF) {
        cout << -1 << '\n';
    } else {
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
            if (v == 1) break;
        }
        reverse(path.begin(), path.end());
 
        for (size_t i = 0; i < path.size(); ++i) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << '\n';
    }
 
    return 0;
}