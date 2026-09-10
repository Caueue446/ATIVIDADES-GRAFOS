#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
    }

    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<bool> visitado(n, false);
    pq.push({0, 0});

    while(!pq.empty()) {
        int a = pq.top().second;
        pq.pop();
        if (visitado[a]) {
            continue;
        }
        visitado[a] = true;
        for (auto i : adj[a]) {
            int b = i.first;
            long long c = i.second;
            if (dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                pq.push({dist[b], b});
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
}