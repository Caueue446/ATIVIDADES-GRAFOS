#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int consolida_numero() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    return a * 1000 + b * 100 + c * 10 + d;
}

int main() {
    int casos;
    cin >> casos;

    while (true) {
        if(casos == 0) {
            break;
        }
        casos -= 1;

        int inicio = consolida_numero();
        int destino = consolida_numero();

        int k;
        cin >> k;

        vector<int> dist(10000, -1);

        for (int i = 0; i < k; i++) {
            int proibido = consolida_numero();
            dist[proibido] = -2;
        }
        if (dist[inicio] == -2 || dist[destino] == -2) {
            cout << -1 << endl;
            continue;
        }

        queue<int> fila;
        fila.push(inicio);
        dist[inicio] = 0;

        int slots[4] = {1000, 100, 10, 1};

        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();

            if (atual == destino) {
                break;
            }

            for (int pos = 0; pos < 4; pos++) {
                int digito = (atual / slots[pos]) % 10;

                int digito_prox = (digito + 1) % 10;
                int vizinho1 = atual - (digito * slots[pos]) + (digito_prox * slots[pos]);

                if (dist[vizinho1] == -1) {
                    dist[vizinho1] = dist[atual] + 1;
                    fila.push(vizinho1);
                }

                int digito_ant = (digito + 9) % 10;
                int vizinho2 = atual - (digito * slots[pos]) + (digito_ant * slots[pos]);

                if (dist[vizinho2] == -1) {
                    dist[vizinho2] = dist[atual] + 1;
                    fila.push(vizinho2);
                }
            }
        }

        cout << dist[destino] << endl;
    }

    return 0;
}