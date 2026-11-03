//
// Created by tjona on 17/09/2026.
#include "Gerador.h"
#include <random>
#include <ctime>

using namespace std;

vector<int> gerarCrescente(int tamanho) {
    vector<int> vetor(tamanho);
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }
    return vetor;
}

vector<int> gerarDecrescente(int tamanho) {
    vector<int> vetor(tamanho);
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
    return vetor;
}

vector<int> gerarRandom(int tamanho) {
    vector<int> vetor(tamanho);
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(1, tamanho * 2);

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = dist(gen);
    }
    return vetor;
}