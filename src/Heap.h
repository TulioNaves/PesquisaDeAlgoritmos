#ifndef ENTREGA1_HEAP_H
#define ENTREGA1_HEAP_H

#include <vector>

// Heap MINIMO com indices a partir de 0:
// pai de i = (i - 1) / 2, filho esquerdo = 2i + 1, filho direito = 2i + 2

// Desce o elemento da posicao i ate o lugar certo, restaurando o heap minimo
void MIN_HEAPIFY(std::vector<int>& A, int tamanhoHeap, int i);

// Transforma o vetor inteiro em heap minimo
void BUILD_MIN_HEAP(std::vector<int>& A);

// Ordena usando heap minimo (o vetor final fica em ordem DECRESCENTE)
void HEAPSORT_MIN(std::vector<int>& A);

#endif //ENTREGA1_HEAP_H
