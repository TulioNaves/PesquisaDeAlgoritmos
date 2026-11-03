#include "Tempo.h"
#include <ctime>

double medirTempo(std::function<void(std::vector<int>&)> algoritmo, std::vector<int>& vetor) {
    clock_t inicio = clock();
    algoritmo(vetor);
    clock_t fim = clock();
    return double(fim - inicio) / CLOCKS_PER_SEC;
}