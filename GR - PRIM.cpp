#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

struct Aresta {
    int vertice;
    int peso;
};

void prim(list<Aresta> adj[], int nVertices, int inicio) {
    vector<bool> naArvore(nVertices, false);
    vector<int> distancia(nVertices, INT_MAX);
    vector<int> pai(nVertices, -1);

    distancia[inicio] = 0;
    int v = inicio;

    while (!naArvore[v]) {
        naArvore[v] = true;
        for (auto &p : adj[v]) {
            int destino = p.vertice;
            int peso = p.peso;
            if (distancia[destino] > peso && !naArvore[destino]) {
                distancia[destino] = peso;
                pai[destino] = v;
            }
        }

        v = 0;
        int dist = INT_MAX;
        for (int u = 0; u < nVertices; ++u) {
            if (!naArvore[u] && dist > distancia[u]) {
                dist = distancia[u];
                v = u;
            }
        }
    }

    int custoTotal = 0;
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 0; i < nVertices; ++i) {
        if (pai[i] != -1) {
            cout << pai[i] << " " << i << endl;
            custoTotal += distancia[i];
        }
    }
    cout << "Custo: " << custoTotal << endl;
}

int main() {
    int nVertices, ehOrientado, verticeInicial;
    cin >> nVertices >> ehOrientado >> verticeInicial;

    list<Aresta> adj[nVertices];

    while (true) {
        int u, v, peso;
        cin >> u >> v >> peso;
        if (u == -1 && v == -1 && peso == -1) break;
        adj[u].push_back({v, peso});
        if (!ehOrientado) {
            adj[v].push_back({u, peso});
        }
    }

    prim(adj, nVertices, verticeInicial);

    return 0;
}