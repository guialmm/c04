#include <iostream>
using namespace std;

int buscaBinaria(int vetor[], int inicio, int fim, int valor) {
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor)
            return meio;

        if (vetor[meio] > valor)
            return buscaBinaria(vetor, inicio, meio - 1, valor);

        return buscaBinaria(vetor, meio + 1, fim, valor);
    }

    return -1;
}

int main() {
    int N, valor;
    
    cin >> N;

    int vetor[N];

    for (int i = 0; i < N; i++) {
        cin >> vetor[i];
    }

    cin >> valor;

    int resultado = buscaBinaria(vetor, 0, N - 1, valor);

    cout << resultado << endl;

    return 0;
}
