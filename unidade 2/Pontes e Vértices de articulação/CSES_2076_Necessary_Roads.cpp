#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000000;
int tin[MAX], low[MAX];
vector<int> adj[MAX];
bool visitado[MAX];
int timer = 0;

vector<pair<int, int>> totalPontes;

void dfs(int a, int pai = -1) {
    visitado[a] = true;
    tin[a] = low[a] = timer++;
    for (int b : adj[a]) {
        if (b == pai)
            continue;
        if (visitado[b]) {
            low[a] = min(low[a], tin[b]);
        } else {
            dfs(b, a);
            low[a] = min(low[a], low[b]);
            if (low[b] > tin[a]) {
                totalPontes.push_back({a, b});
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << totalPontes.size() << "\n";
    for (auto x : totalPontes) {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}