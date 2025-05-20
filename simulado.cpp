#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

#define INT_MAX 99999

struct Estrada {
    int dest;
    int distancia;
};

struct Cidade {
    string nome;
    int codigo;
    float idh;
    list<Estrada> vizinhos;
};

int shortest_path_dijkstra(vector<Cidade>& cidades, int vertices, int start, int end, float idh_min) {
    vector<bool> intree(vertices, false);
    vector<int> distance(vertices, INT_MAX);
    vector<int> parent(vertices, -1);

    distance[start] = 0;
    int v = start;

    while (!intree[v]) {
        intree[v] = true;

        for (const auto& estrada : cidades[v].vizinhos) {
            if (cidades[estrada.dest].idh >= idh_min) {
                int dest = estrada.dest;
                int weight = estrada.distancia;
                if (distance[dest] > distance[v] + weight) {
                    distance[dest] = distance[v] + weight;
                    parent[dest] = v;
                }
            }
        }

        v = 0;
        int dist = INT_MAX;
        for (int u = 0; u < vertices; u++) {
            if (!intree[u] && dist > distance[u]) {
                dist = distance[u];
                v = u;
            }
        }
    }

    return distance[end] == INT_MAX ? -1 : distance[end];
}

int main() {
    int num_cidades;
    cin >> num_cidades;

    vector<Cidade> cidades(num_cidades);

    for (int i = 0; i < num_cidades; i++) {
        cidades[i].codigo = i;
        cin >> cidades[i].nome >> cidades[i].idh;
    }

    int num_estradas;
    cin >> num_estradas;

    for (int j = 0; j < num_estradas; j++) {
        int origem, destino, distancia;
        cin >> origem >> destino >> distancia;
        cidades[origem].vizinhos.push_back({destino, distancia});
        cidades[destino].vizinhos.push_back({origem, distancia}); // Estradas bidirecionais
    }

    int origem, destino;
    float idh_min;
    cin >> origem >> destino >> idh_min;

    int resultado = shortest_path_dijkstra(cidades, num_cidades, origem, destino, idh_min);
    if (resultado != -1) {
        cout << resultado << endl;
    } else {
        cout << "Nao ha caminho valido" << endl;
    }

    return 0;
}