//
// Created by tjona on 17/11/2026.
//
#include "FilaDePrioridade.h"
#include "Heap.h"
#include <utility>
using namespace std;

// Sobe o elemento da posicao i enquanto ele for menor que o pai
static void subirNoHeap(vector<int>& A, int i) {
    while (i > 0 && A[i] < A[(i - 1) / 2]) {
        int pai = (i - 1) / 2;
        swap(A[i], A[pai]);
        i = pai;
    }
}

// A raiz de um heap minimo e sempre o menor elemento
int HEAP_MINIMUM(const vector<int>& A) {
    return A[0];
}

// Guarda a raiz, move o ultimo elemento para a raiz, diminui o heap
// e chama MIN_HEAPIFY na raiz para restaurar a propriedade
int HEAP_EXTRACT_MIN(vector<int>& A) {
    int n = A.size();
    int minimo = A[0];
    A[0] = A[n - 1];
    A.pop_back();
    int tamanhoHeap = n - 1;
    MIN_HEAPIFY(A, tamanhoHeap, 0);
    return minimo;
}

// Como o heap e minimo, a logica de restauracao e a do heap minimo:
// se a nova chave ficou maior que os filhos, MIN_HEAPIFY desce a chave;
// se ficou menor que o pai, ela precisa subir (caso contrario nada muda).
void HEAP_INCREASE_KEY(vector<int>& A, int i, int chave) {
    int tamanhoHeap = A.size();
    A[i] = chave;
    MIN_HEAPIFY(A, tamanhoHeap, i);
    subirNoHeap(A, i);
}

// Como o heap e minimo, a logica de restauracao e a do heap minimo:
// coloca a chave no fim e sobe enquanto ela for menor que o pai
void MAX_HEAP_INSERT(vector<int>& A, int chave) {
    A.push_back(chave);
    int i = A.size() - 1;
    subirNoHeap(A, i);
}
