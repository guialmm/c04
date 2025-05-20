#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType;
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

Node *search(Node *curr, KeyType key) {
    if (curr == NULL)
        return NULL;
    if (key == curr->data.key) {
        return curr;
    } else {
        if (key > curr->data.key) {
            return search(curr->right, key);
        } else if (key < curr->data.key) {
            return search(curr->left, key);
        }
    }
    return NULL;
}

void show_ordered(Node *curr) {
    if (curr->left != NULL)
        show_ordered(curr->left);
    cout << curr->data.key << ":" << curr->data.value << endl;
    if (curr->right != NULL)
        show_ordered(curr->right);
}

void show_levels(Node *curr, int Tmin, int Tmax) {
    if (curr == NULL) {
        return;
    }

    queue<Node *> nodes;
    nodes.push(curr);
    map<int, DataType> result;

    while (!nodes.empty()) {
        Node *aux = nodes.front();
        nodes.pop();
        if (aux->data.value >= Tmin && aux->data.value <= Tmax) {
            result[aux->data.key] = aux->data;
        }

        if (aux->left != NULL)
            nodes.push(aux->left);

        if (aux->right != NULL)
            nodes.push(aux->right);
    }

    for (const auto &pair : result) {
        cout << pair.second.key << ":" << pair.second.value << endl;
    }
}

Node *disconnect_lesser(Node *&curr) {
    Node *aux = curr;
    if (aux->left == NULL) {
        curr = curr->right;
        return aux;
    } else {
        return disconnect_lesser(curr->left);
    }
}

int remove(Node *&curr, KeyType old_key) {
    if (curr == NULL) {
        return 0;
    }
    Node *aux;
    if (curr->data.key == old_key) {
        aux = curr;
        if (curr->left == NULL) {
            curr = aux->right;
        } else if (curr->right == NULL) {
            curr = aux->left;
        } else {
            aux = disconnect_lesser(curr->right);
            curr->data = aux->data;
        }
        delete aux;
        return 1;
    } else {
        if (old_key > curr->data.key) {
            return remove(curr->right, old_key);
        } else if (old_key < curr->data.key) {
            return remove(curr->left, old_key);
        }
    }
    return 0;
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

// ----------------------------------------------------------------------------

int main() {
    int P;
    cin >> P;

    Node *root = NULL;
    const int N = 7;

    for (int i = 0; i < P; ++i) {
        double V, E, O;
        cin >> V >> E >> O;
        int T = static_cast<int>(V * E * N * E * N * O);
        DataType data = {i, T};
        insert(root, data);
    }

    int Tmin, Tmax;
    cin >> Tmin >> Tmax;

    show_levels(root, Tmin, Tmax);

    destruct(root);

    return 0;
}