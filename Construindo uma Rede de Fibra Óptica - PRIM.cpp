#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int prim(int N, vector<vector<pii>>& adj) {
    vector<bool> visitado(N + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int custo_total = 0;

    pq.push({0, 1});

    while (!pq.empty()) {
        int custo = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visitado[u]) continue;
        visitado[u] = true;
        custo_total += custo;

        for (auto& aresta : adj[u]) {
            int v = aresta.first;
            int proximo_custo = aresta.second;
            if (!visitado[v]) {
                pq.push({proximo_custo, v});
            }
        }
    }

    return custo_total;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pii>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    int resultado = prim(N, adj);
    cout << resultado << endl;

    return 0;
}