#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(int cidade, vector<vector<int>>& adj, vector<bool>& visitado) {
    visitado[cidade] = true;
    for (int vizinho : adj[cidade]) {
        if (!visitado[vizinho]) {
            bfs(vizinho, adj, visitado);
        }
    }
}

int main() {
    int numCidades, numCaminhos;
    cin >> numCidades >> numCaminhos;

    vector<vector<int>> adj(numCidades + 1);

    for (int i = 0; i < numCaminhos; ++i) {
        int cidadeA, cidadeB;
        cin >> cidadeA >> cidadeB;
        adj[cidadeA].push_back(cidadeB);
        adj[cidadeB].push_back(cidadeA);
    }

    int cidadeX, cidadeY;
    cin >> cidadeX >> cidadeY;

    // Remover a ponte entre cidadeX e cidadeY
    adj[cidadeX].erase(remove(adj[cidadeX].begin(), adj[cidadeX].end(), cidadeY), adj[cidadeX].end());
    adj[cidadeY].erase(remove(adj[cidadeY].begin(), adj[cidadeY].end(), cidadeX), adj[cidadeY].end());

    vector<bool> visitado(numCidades + 1, false);
    dfs(cidadeX, adj, visitado);

    bool primeiro = true;
    for (int i = 1; i <= numCidades; ++i) {
        if (!visitado[i]) {
            if (!primeiro) {
                cout << " ";
            }
            cout << i;
            primeiro = false;
        }
    }
    cout << endl;

    return 0;
}