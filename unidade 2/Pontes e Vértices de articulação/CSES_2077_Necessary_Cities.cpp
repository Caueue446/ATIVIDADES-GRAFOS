#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000000;
int tin[MAX], low[MAX];
vector<int> adj[MAX];
bool visitado[MAX];
int timer = 0;
bool articulacao[MAX];

void dfs(int u, int pai =-1) {
    visitado[u] = true;
    tin[u] = low[u] = timer++;
    int num_filhos = 0;
    for (int v : adj[u]) {
        if (v == pai)
            continue;
        if (visitado[v])
            low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (pai !=-1 && low[v] >= tin[u])
                articulacao[u] = true;
            num_filhos++;
        }
    }
    if (pai ==-1 && num_filhos >= 2)
        articulacao[u] = true;
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

    vector<int> TotalArticulacao;
    for (int i = 1; i <= n; i++) {
        if (articulacao[i]) {
            TotalArticulacao.push_back(i);
        }
    }

    cout << TotalArticulacao.size() << "\n";
    for (int x : TotalArticulacao) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}