#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct no {
    int v;     // vertice adjacente
    int peso;  // peso da aresta
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado) {
    adj[u].push_back({v, p});
    if (!orientado && u != v) {
        adj[v].push_back({u, p});
    }
}

int main() {
    int num_vertices, orientado;
    cin >> num_vertices >> orientado;
    list<no> adj[num_vertices];

    int origem, destino, peso;
    while (cin >> origem >> destino >> peso) {
        if (origem == -1 && destino == -1 && peso == -1) break;
        cria_aresta(adj, origem, destino, peso, orientado);
    }

    for (int i = 0; i < num_vertices; i++) {
        for (auto& no : adj[i]) {
            cout << i << " " << no.v << " " << no.peso << "\n";
        }
    }

    return 0;
}