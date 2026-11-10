//
// Created by tjona on 09/11/2026.
//
#include "QuickSort.h"
#include <utility>
using namespace std;

// Particiona A[inicio..fim] usando A[inicio] como pivo (estilo Sedgewick).
// O i avanca da esquerda procurando um elemento maior ou igual ao pivo,
// o j recua da direita procurando um elemento menor ou igual ao pivo,
// e os dois sao trocados ate os indices se cruzarem.
// No fim, o pivo vai para a posicao j, que e a sua posicao final.
static int particionar(vector<int>& A, int inicio, int fim) {
    int pivo = A[inicio];
    int i = inicio;
    int j = fim + 1;

    while (true) {
        // Avanca i enquanto o elemento for menor que o pivo
        while (A[++i] < pivo) {
            if (i == fim) break;
        }
        // Recua j enquanto o elemento for maior que o pivo
        while (pivo < A[--j]) {
            if (j == inicio) break;
        }
        // Se os indices se cruzaram, a particao terminou
        if (i >= j) break;
        swap(A[i], A[j]);
    }

    // Coloca o pivo na posicao final
    swap(A[inicio], A[j]);
    return j;
}

// Leva a mediana entre o primeiro, o meio e o ultimo elemento para A[inicio].
// Primeiro ordena os tres (A[inicio] <= A[meio] <= A[fim]) e depois troca
// a mediana (que ficou no meio) com o primeiro. Ordenar os tres antes evita
// que o maior valor fique perdido no meio do trecho, o que deixaria o
// algoritmo quadratico em vetores decrescentes.
static void medianaDeTres(vector<int>& A, int inicio, int fim) {
    int meio = inicio + (fim - inicio) / 2;

    if (A[meio] < A[inicio]) swap(A[meio], A[inicio]);
    if (A[fim] < A[inicio]) swap(A[fim], A[inicio]);
    if (A[fim] < A[meio]) swap(A[fim], A[meio]);

    // Agora a mediana esta em A[meio]: leva para a primeira posicao
    swap(A[inicio], A[meio]);
}

// Versao 1: pivo e o primeiro elemento do trecho
static void quickSortV1Recursivo(vector<int>& A, int inicio, int fim) {
    if (inicio >= fim) return;
    int p = particionar(A, inicio, fim);
    quickSortV1Recursivo(A, inicio, p - 1);
    quickSortV1Recursivo(A, p + 1, fim);
}

// Versao 2: igual a versao 1, mas antes leva a mediana de tres para o inicio
static void quickSortV2Recursivo(vector<int>& A, int inicio, int fim) {
    if (inicio >= fim) return;
    medianaDeTres(A, inicio, fim);
    int p = particionar(A, inicio, fim);
    quickSortV2Recursivo(A, inicio, p - 1);
    quickSortV2Recursivo(A, p + 1, fim);
}

void QuickSortV1(vector<int>& A) {
    int n = A.size();
    quickSortV1Recursivo(A, 0, n - 1);
}

void QuickSortV2(vector<int>& A) {
    int n = A.size();
    quickSortV2Recursivo(A, 0, n - 1);
}
