#include <iostream>
#include <vector>

using namespace std;

bool ehConexo(int numVertices, int verticeInicial, vector<vector<int>>& listaAdjacencia) {
    vector<bool> visitado(numVertices, false);
    vector<int> fila;
    fila.push_back(verticeInicial);
    visitado[verticeInicial] = true;
    int contagemVisitados = 1;

    while (!fila.empty()) {
        int vertice = fila.front();
        fila.erase(fila.begin());

        for (int vizinho : listaAdjacencia[vertice]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                fila.push_back(vizinho);
                contagemVisitados++;
            }
        }
    }

    return contagemVisitados == numVertices;
}

int main() {
    int numVertices, verticeInicial;
    cin >> numVertices >> verticeInicial;

    vector<vector<int>> listaAdjacencia(numVertices);

    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        listaAdjacencia[u].push_back(v);
        listaAdjacencia[v].push_back(u);
    }

    if (ehConexo(numVertices, verticeInicial, listaAdjacencia)) {
        cout << "Conexo" << endl;
    } else {
        cout << "Nao conexo" << endl;
    }

    return 0;
}