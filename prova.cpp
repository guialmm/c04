#include <iostream>
#include <cmath>

using namespace std;

// Estruturas para a Árvore Binária
typedef int KeyType;
typedef int ValueType;

struct DataType {
    KeyType key;
    ValueType value;
};

struct Node {
    DataType data;
    Node *right;
    Node *left;
};

void insert(Node *&curr, DataType data) {
    if (curr == NULL) {
        curr = new Node;
        curr->data = data;
        curr->right = NULL;
        curr->left = NULL;
    } else {
        if (data.value > curr->data.value || 
            (data.value == curr->data.value && data.key > curr->data.key)) {
            insert(curr->right, data);
        } else {
            insert(curr->left, data);
        }
    }
}

void show_ordered(Node *curr, int PFmin, int PFmax) {
    if (curr == NULL) return;
    show_ordered(curr->left, PFmin, PFmax);
    if (curr->data.value >= PFmin && curr->data.value <= PFmax)
        cout << curr->data.key << ":" << curr->data.value << endl;
    show_ordered(curr->right, PFmin, PFmax);
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

// Estruturas e Funções Auxiliares
typedef struct {
    int x;
    int y;
} Ponto;

double distancia(Ponto p1, Ponto p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Função Principal
int main() {
    int T;
    cin >> T;

    Node *root = NULL;

    for (int i = 0; i < T; i++) {
        Ponto A, B, C, D;
        int peso;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y >> peso;

        double EM = distancia(A, B);
        double diametro = distancia(A, D);
        double altura = distancia(A, C);

        int PF = static_cast<int>(std::floor(EM * peso * altura + diametro + altura));

        DataType data = {i, PF};
        insert(root, data);
    }

    int PFmin, PFmax;
    cin >> PFmin >> PFmax;

    show_ordered(root, PFmin, PFmax);

    destruct(root);

    return 0;
}
