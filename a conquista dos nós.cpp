#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    
    cin >> N >> M;
    
    vector<vector<int>> matriz_adj(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        
        A--;
        B--;
        
        matriz_adj[A][B] = 1;
        matriz_adj[B][A] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz_adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
