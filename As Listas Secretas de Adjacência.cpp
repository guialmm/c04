#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numCidades, numCaminhos;
    cin >> numCidades >> numCaminhos;

    vector<vector<int>> listaAdjacencia(numCidades + 1);

    for (int i = 0; i < numCaminhos; ++i) {
        int cidadeA, cidadeB;
        cin >> cidadeA >> cidadeB;
        listaAdjacencia[cidadeA].push_back(cidadeB);
        listaAdjacencia[cidadeB].push_back(cidadeA);
    }

    for (int i = 1; i <= numCidades; ++i) {
        sort(listaAdjacencia[i].begin(), listaAdjacencia[i].end());
        cout << listaAdjacencia[i].size();
        for (int cidade : listaAdjacencia[i]) {
            cout << " " << cidade;
        }
        cout << endl;
    }

    return 0;
}