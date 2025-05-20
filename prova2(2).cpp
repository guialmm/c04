#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef double KeyType;
typedef int ValueType;

struct Data {
    KeyType key;
    ValueType value;
};

typedef struct Data DataType;

typedef struct Node {
    DataType data;
    Node *right;
    Node *left;
} Node;

void insert(Node *&curr, DataType data) {
    if (curr == NULL) {
        curr = new Node;
        curr->data = data;
        curr->right = NULL;
        curr->left = NULL;
    } else {
        if (data.key >= curr->data.key) {
            insert(curr->right, data);
        } else if (data.key < curr->data.key) {
            insert(curr->left, data);
        }
    }
}

void show_ordered(Node *curr) {
    if (curr->right != NULL)
        show_ordered(curr->right);
    cout << curr->data.value << ":" << curr->data.key << endl;
    if (curr->left != NULL)
        show_ordered(curr->left);
}

void destruct(Node *&curr) {
    if (curr->left != NULL)
        destruct(curr->left);
    if (curr->right != NULL)
        destruct(curr->right);
    delete curr;
    curr = NULL;
    return;
}

// Funções para Algoritmos Geométricos ----------------------------------------

typedef struct {
    int x;
    int y;
} Ponto;

double distancia(Ponto p1, Ponto p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double calcular_comprimento(Ponto p1, Ponto p2, Ponto p3) {
    double d1 = distancia(p1, p2);
    double d2 = distancia(p1, p3);
    return max(d1, d2);
}

// ----------------------------------------------------------------------------

int main() {
    int P;
    cin >> P;

    Node *root = NULL;

    for (int i = 0; i < P; ++i) {
        Ponto p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

        double comprimento = calcular_comprimento(p1, p2, p3);
        DataType data = {comprimento, i};
        insert(root, data);
    }

    cout << "Arvore ordenada:";
    cout << endl;
    

    show_ordered(root);
    destruct(root);

    return 0;
}