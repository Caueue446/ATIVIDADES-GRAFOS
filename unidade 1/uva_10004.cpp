#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        int qtdArestas;
        cin >> qtdArestas;
        vector<vector<int>> adj(n);

        for (int j = 0; j < qtdArestas; j++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> cor(n, -1);
        stack<int> pilha;

        pilha.push(0);
        cor[0] = 0;

        bool bipartido = true;

        while (!pilha.empty() && bipartido) {
            int k = pilha.top();
            pilha.pop();

            for (auto i : adj[k]) {
                if (cor[i] == -1) {
                    cor[i] = 1 - cor[k];
                    pilha.push(i);
                } else if (cor[i] == cor[k]) {
                    bipartido = false;
                    break;
                }
            }
        }

        if (bipartido) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }

    return 0;
}