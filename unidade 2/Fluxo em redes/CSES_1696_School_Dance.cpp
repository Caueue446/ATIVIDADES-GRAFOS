#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> match;
vector<bool> visitado;

bool dfs(int boy) {
    for (int girl : adj[boy]) {
        if (visitado[girl]) continue;
        visitado[girl] = true;

        if (match[girl] == -1 || dfs(match[girl])) {
            match[girl] = boy;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    adj.resize(n + 1);
    
    match.assign(m + 1, -1);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int pares = 0;
    
    for (int i = 1; i <= n; i++) {
        visitado.assign(m + 1, false);
        
        if (dfs(i)) {
            pares++;
        }
    }

    cout << pares << "\n";
    
    for (int girl = 1; girl <= m; girl++) {
        if (match[girl] != -1) { 
            cout << match[girl] << " " << girl << "\n";
        }
    }

    return 0;
}