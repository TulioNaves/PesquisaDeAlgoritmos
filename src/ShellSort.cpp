//
// Created by tjona on 23/09/2026.
//
#include "ShellSort.h"
using namespace std;

void ShellSort(vector<int>& A) {
    int n = A.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = A[i];
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
    }
}