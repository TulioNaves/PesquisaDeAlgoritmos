//
// Created by tjona on 17/11/2026.
//
#include "Heap.h"
#include <utility>
using namespace std;

// Compara o elemento da posicao i com seus filhos. Se algum filho for menor,
// troca o elemento com o menor filho e continua descendo a partir dali.
// Para quando o elemento for menor ou igual aos filhos ou virar folha.
void MIN_HEAPIFY(vector<int>& A, int tamanhoHeap, int i) {
    int esquerdo = 2 * i + 1;
    int direito = 2 * i + 2;
    int menor = i;

    // O filho esquerdo existe e e menor que o atual?
    if (esquerdo < tamanhoHeap && A[esquerdo] < A[menor]) {
        menor = esquerdo;
    }
    // O filho direito existe e e menor que o menor ate agora?
    if (direito < tamanhoHeap && A[direito] < A[menor]) {
        menor = direito;
    }
    // Se o menor e um filho, troca e desce para a posicao dele
    if (menor != i) {
        swap(A[i], A[menor]);
        MIN_HEAPIFY(A, tamanhoHeap, menor);
    }
}

// Chama MIN_HEAPIFY de baixo para cima, do ultimo no interno ate a raiz.
// As folhas (posicoes n/2 ate n-1) ja sao heaps de um elemento.
void BUILD_MIN_HEAP(vector<int>& A) {
    int n = A.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        MIN_HEAPIFY(A, n, i);
    }
}

// Monta o heap minimo e, a cada passo, leva a raiz (o menor elemento)
// para o fim do heap, diminui o heap e restaura a propriedade na raiz.
// Como os menores vao para o fim, o vetor termina em ordem DECRESCENTE.
void HEAPSORT_MIN(vector<int>& A) {
    int n = A.size();
    BUILD_MIN_HEAP(A);
    int tamanhoHeap = n;
    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        tamanhoHeap = tamanhoHeap - 1;
        MIN_HEAPIFY(A, tamanhoHeap, 0);
    }
}
