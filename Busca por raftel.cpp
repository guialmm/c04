#include <iostream>
#include <string>

using namespace std;

int buscaPoneglyph(string arr[], int tamanho, string pista) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == pista) {
            return meio;
        }
        if (arr[meio] < pista) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    string ilhas[] = {"Alabasta", "Dressrosa", "Enies Lobby", "Skypiea", "Thriller Bark", "Wano", "Water 7", "Skypiea"};
    int tamanho = sizeof(ilhas) / sizeof(ilhas[0]);
    string pista = "Skypiea";

    int indice = buscaPoneglyph(ilhas, tamanho, pista);

    if (indice != -1) {
        cout << "Índice da pista encontrada: " << indice << endl;
    } else {
        cout << "Pista não encontrada" << endl;
    }

    return 0;
}