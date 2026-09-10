#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    int c;
    cin >> c;

    while (c) {
        if(c == 0) {
            break;
        }
        c -= 1;
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INF);
        dist[0] = 0; 

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[j] == INF) continue;

                for (auto u : adj[j]) {
                    int k = u.first;
                    int peso = u.second;

                    if (dist[j] + peso < dist[k]) {
                        dist[k] = dist[j] + peso;
                    }
                }
            }
        }

        bool ciclo_negativo = false;

        for (int j = 0; j < n; j++) {
            if (dist[j] == INF) continue;

            for (auto u : adj[j]) {
                int k = u.first;
                int peso = u.second;

                if (dist[j] + peso < dist[k]) {
                    ciclo_negativo = true;
                    break;
                }
            }
            if (ciclo_negativo) break;
        }

        if (ciclo_negativo) {
            cout << "POSSIBLE\n";
        } else {
            cout << "NOT POSSIBLE\n";
        }
    }

    return 0;
}