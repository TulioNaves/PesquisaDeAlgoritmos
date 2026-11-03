//
// Created by tjona on 23/09/2026.
//
#include "SelectionSort.h"
using namespace std;

void SelectionSort(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        int temp = A[min_idx];
        A[min_idx] = A[i];
        A[i] = temp;
    }
}