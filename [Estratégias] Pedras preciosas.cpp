#include <iostream>
#include <string>

using namespace std;

struct Pedra {
    string nome;
    double volume;
    double peso;
    int valor;
};

int main() {
    int N;
    cin >> N;
    Pedra pedras[N];

    for (int i = 0; i < N; i++) {
        cin >> pedras[i].nome >> pedras[i].volume >> pedras[i].peso >> pedras[i].valor;
    }

    const double volumeMaximo = 1.0;
    const int pesoMaximo = 400;

    int volumeMaximoInt = volumeMaximo * 1000;

    int dp[pesoMaximo + 1][volumeMaximoInt + 1];
    int manter[pesoMaximo + 1][volumeMaximoInt + 1];

    for (int i = 0; i <= pesoMaximo; ++i) {
        for (int j = 0; j <= volumeMaximoInt; ++j) {
            dp[i][j] = 0;
            manter[i][j] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        int volumePedraInt = pedras[i].volume * 1000;
        for (int p = pesoMaximo; p >= pedras[i].peso; --p) {
            for (int v = volumeMaximoInt; v >= volumePedraInt; --v) {
                if (dp[p - static_cast<int>(pedras[i].peso)][v - volumePedraInt] + pedras[i].valor > dp[p][v]) {
                    dp[p][v] = dp[p - static_cast<int>(pedras[i].peso)][v - volumePedraInt] + pedras[i].valor;
                    manter[p][v] = i;
                }
            }
        }
    }

    int pesoRestante = pesoMaximo;
    int volumeRestante = volumeMaximoInt;
    string resultado[N];
    int count = 0;

    while (pesoRestante > 0 && volumeRestante > 0 && manter[pesoRestante][volumeRestante] != -1) {
        int i = manter[pesoRestante][volumeRestante];
        resultado[count++] = pedras[i].nome;
        pesoRestante -= pedras[i].peso;
        volumeRestante -= pedras[i].volume * 1000;
    }

    for (int i = count - 1; i >= 0; --i) {
        cout << resultado[i] << endl;
    }

    return 0;
}