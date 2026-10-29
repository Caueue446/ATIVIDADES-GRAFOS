#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

long long capacity[505][505];
vector<int> adj[505];

bool bfs(int src, int sink, vector<int>& parent, int n) {
    vector<bool> vis(n + 1, false);
    queue<int> q;
    
    q.push(src);
    vis[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v] && capacity[u][v] > 0) {
                vis[v] = true;
                parent[v] = u;
                
                if (v == sink) return true;
                
                q.push(v);
            }
        }
    }
    return false;
}

long long findMaxFlow(int src, int sink, int n) {
    long long maxFlow = 0;
    vector<int> parent(n + 1);

    while (bfs(src, sink, parent, n)) {
        long long pathFlow = INF;

        for (int v = sink; v != src; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v]);
        }

        for (int v = sink; v != src; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long cap;
        cin >> u >> v >> cap;
        
        if (capacity[u][v] == 0 && capacity[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        
        capacity[u][v] += cap;
    }

    cout << findMaxFlow(1, n, n) << "\n";

    return 0;
}