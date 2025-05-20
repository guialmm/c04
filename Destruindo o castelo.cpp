#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochila(int N, vector<pair<int, int>> &projetil, int K) {
    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++) {
        int destruicao = projetil[i].first;
        int peso = projetil[i].second;

        for (int j = K; j >= peso; j--) {
            dp[j] = max(dp[j], dp[j - peso] + destruicao);
        }
    }

    return dp[K];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> projetil(N);
        
        for (int i = 0; i < N; i++) {
            cin >> projetil[i].first >> projetil[i].second;
        }

        int K;
        cin >> K;

        int R;
        cin >> R;

        int danoMaximo = mochila(N, projetil, K);

        if (danoMaximo >= R) {
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "Falha na missao" << endl;
        }
    }

    return 0;
}
