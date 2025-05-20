#include <iostream>
#include <vector>

using namespace std;

long long mesclar_e_contar(vector<int>& vetor, int esquerda, int meio, int direita) {
    vector<int> vetorEsquerda(vetor.begin() + esquerda, vetor.begin() + meio + 1);
    vector<int> vetorDireita(vetor.begin() + meio + 1, vetor.begin() + direita + 1);

    int i = 0, j = 0, k = esquerda;
    long long contagem_inversoes = 0;

    while (i < vetorEsquerda.size() && j < vetorDireita.size()) {
        if (vetorEsquerda[i] <= vetorDireita[j]) {
            vetor[k++] = vetorEsquerda[i++];
        } else {
            vetor[k++] = vetorDireita[j++];
            contagem_inversoes += vetorEsquerda.size() - i;
        }
    }

    while (i < vetorEsquerda.size()) vetor[k++] = vetorEsquerda[i++];
    while (j < vetorDireita.size()) vetor[k++] = vetorDireita[j++];

    return contagem_inversoes;
}

long long ordena_e_conta(vector<int>& vetor, int esquerda, int direita) {
    long long contagem_inversoes = 0;
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        contagem_inversoes += ordena_e_conta(vetor, esquerda, meio);
        contagem_inversoes += ordena_e_conta(vetor, meio + 1, direita);
        contagem_inversoes += mesclar_e_contar(vetor, esquerda, meio, direita);
    }
    return contagem_inversoes;
}

int main() {
    int N;
    cin >> N;

    vector<int> vetor(N);
    for (int i = 0; i < N; i++) {
        cin >> vetor[i];
    }

    long long inversoes = ordena_e_conta(vetor, 0, N - 1);
    cout << inversoes << endl;

    return 0;
}
