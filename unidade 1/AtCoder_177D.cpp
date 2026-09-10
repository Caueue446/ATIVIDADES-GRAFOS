#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int resultado = 0;
    vector<bool> visitado(n, false);

    for (int j = 0; j < n; j++) {

        if (visitado[j]) {
            continue;
        }

        int t = 0;
        stack<int> pilha;
        pilha.push(j);
        visitado[j] = true;

        while (!pilha.empty()) {
            int k = pilha.top();
            pilha.pop();
            t++;
            for (auto i : adj[k]) {
                if (!visitado[i]) {
                    visitado[i] = true;
                    pilha.push(i);
                }
            }
        }
        resultado = max(resultado, t);
    }
    cout << resultado << endl;
    return 0;
}