//
// Created by tjona on 17/09/2026.
//
#include "InsertionSort.h"

void insertionSort(vector<int>& A) {
    int n = A.size();
    for (int j = 1; j < n; j++) {
        int chave = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > chave) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = chave;
    }
}