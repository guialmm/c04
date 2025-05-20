#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

struct no {
    int v;
    int peso;
};

void bfs(list<no> adj[], int nVertices, int s) {
    vector<char> state(nVertices, 'u'); // undiscovered
    vector<int> pai(nVertices, -1); // sem pais
    queue<int> Q;

    state[s] = 'd'; // discovered
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        cout << u << endl;

        for (auto p = adj[u].begin(); p != adj[u].end(); ++p) {
            int v = p->v;
            cout << u << " " << v << endl;
            if (state[v] == 'u') {
                state[v] = 'd';
                pai[v] = u;
                Q.push(v);
            }
        }
        state[u] = 'p'; // processed
    }
}

int main() {
    int nVertices, s;
    cin >> nVertices >> s;

    list<no> adj[nVertices];

    while (true) {
        int origem, destino, peso;
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) break;

        no node;
        node.v = destino;
        node.peso = peso;
        adj[origem].push_back(node);

        node.v = origem;
        adj[destino].push_back(node);
    }

    bfs(adj, nVertices, s);

    return 0;
}