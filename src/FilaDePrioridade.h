#ifndef ENTREGA1_FILADEPRIORIDADE_H
#define ENTREGA1_FILADEPRIORIDADE_H

#include <vector>

// Operacoes de fila de prioridade MINIMA sobre um vetor que ja e heap minimo
// (montado com BUILD_MIN_HEAP). O tamanho do heap e o tamanho do vetor.

// Retorna o menor elemento (a raiz), sem remover
int HEAP_MINIMUM(const std::vector<int>& A);

// Remove e retorna o menor elemento, restaurando o heap minimo
int HEAP_EXTRACT_MIN(std::vector<int>& A);

// Atribui "chave" a posicao i e restaura o heap minimo.
// O nome vem do enunciado (heap maximo); aqui o heap e minimo.
void HEAP_INCREASE_KEY(std::vector<int>& A, int i, int chave);

// Insere "chave" no heap minimo.
// O nome vem do enunciado (heap maximo); aqui o heap e minimo.
void MAX_HEAP_INSERT(std::vector<int>& A, int chave);

#endif //ENTREGA1_FILADEPRIORIDADE_H
