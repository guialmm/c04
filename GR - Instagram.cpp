#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct no {
    int v;  // vertice adjacente
};

void cria_aresta(list<no> adj[], int u, int v) {
    adj[u].push_back({v});
}

int main() {
    int num_usuarios;
    cin >> num_usuarios;
    cin.ignore();

    vector<string> usuarios(num_usuarios);
    for (int i = 0; i < num_usuarios; i++) {
        getline(cin, usuarios[i]);
    }

    list<no> adj[num_usuarios];
    for (int i = 0; i < num_usuarios; i++) {
        int seguidor;
        while (cin >> seguidor && seguidor != -1) {
            cria_aresta(adj, i, seguidor);
        }
    }

    int usuario_verificar;
    cin >> usuario_verificar;

    vector<string> seguidores;
    for (int i = 0; i < num_usuarios; i++) {
        for (auto& no : adj[i]) {
            if (no.v == usuario_verificar) {
                seguidores.push_back(usuarios[i]);
            }
        }
    }

    for (const auto& seguidor : seguidores) {
        cout << seguidor << endl;
    }

    return 0;
}