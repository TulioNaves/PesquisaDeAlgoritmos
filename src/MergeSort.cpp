//
// Created by tjona on 21/10/2026.
//
#include "MergeSort.h"
using namespace std;

// Intercala as metades ordenadas A[inicio..meio] e A[meio+1..fim] usando o vetor auxiliar
static void merge(vector<int>& A, vector<int>& aux, int inicio, int meio, int fim) {
    for (int k = inicio; k <= fim; k++) {
        aux[k] = A[k];
    }
    int i = inicio;
    int j = meio + 1;
    for (int k = inicio; k <= fim; k++) {
        if (i > meio) {
            A[k] = aux[j++];
        } else if (j > fim) {
            A[k] = aux[i++];
        } else if (aux[j] < aux[i]) {
            A[k] = aux[j++];
        } else {
            A[k] = aux[i++];
        }
    }
}

// Divide o intervalo ao meio, ordena cada metade e intercala
static void mergeSortRecursivo(vector<int>& A, vector<int>& aux, int inicio, int fim) {
    if (inicio >= fim) return;
    int meio = inicio + (fim - inicio) / 2;
    mergeSortRecursivo(A, aux, inicio, meio);
    mergeSortRecursivo(A, aux, meio + 1, fim);
    merge(A, aux, inicio, meio, fim);
}

void MergeSort(vector<int>& A) {
    int n = A.size();
    vector<int> aux(n);  // alocado uma unica vez e reaproveitado em todas as chamadas
    mergeSortRecursivo(A, aux, 0, n - 1);
}