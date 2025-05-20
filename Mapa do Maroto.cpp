#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int numVertices, ehOrientado;
    cin >> numVertices >> ehOrientado;

    vector<tuple<int, int, int>> listaArestas;

    while (true) {
        int origem, destino, peso;
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) break;

        listaArestas.emplace_back(origem, destino, peso);
        if (!ehOrientado) {
            listaArestas.emplace_back(destino, origem, peso);
        }
    }

    // Ordenar a lista de arestas primeiro pelo vértice de destino e depois pelo vértice de origem
    sort(listaArestas.begin(), listaArestas.end(), [](const auto& a, const auto& b) {
        if (get<1>(a) == get<1>(b)) {
            return get<0>(a) < get<0>(b);
        }
        return get<1>(a) < get<1>(b);
    });

    for (const auto& aresta : listaArestas) {
        cout << get<0>(aresta) << " " << get<1>(aresta) << " " << get<2>(aresta) << endl;
    }

    return 0;
}