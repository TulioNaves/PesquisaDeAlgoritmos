#include "InsertionSort.h"
#include "Tools/Teste.h"
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <limits>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Heap.h"
#include "FilaDePrioridade.h"
#include "Tools/Gerador.h"

using namespace std;

// Limpa o cin quando o usuario digita algo que nao e numero
void limparEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Retorna os tamanhos que serao testados (um ou todos)
vector<int> escolherTamanhos() {
    const vector<int> tamanhosPadrao = {10, 100, 1000, 10000, 100000, 1000000};
    const int opTodos = tamanhosPadrao.size() + 2;
    int opcao;

    cout << "\nTamanho do vetor:" << endl;
    for (size_t i = 0; i < tamanhosPadrao.size(); i++) {
        cout << i + 1 << " - " << tamanhosPadrao[i] << endl;
    }
    cout << opTodos << " - Todos os tamanhos" << endl;
    cout << "Escolha: ";

    if (!(cin >> opcao)) {
        limparEntrada();
        return {};
    }

    if (opcao >= 1 && opcao <= (int)tamanhosPadrao.size()) {
        return {tamanhosPadrao[opcao - 1]};
    }
    if (opcao == opTodos) {
        return tamanhosPadrao;
    }
    return {};  // opcao invalida
}

//Executa o Algoritmo escolhido
void executarMenuDeTestes(function<void(vector<int>&)> algoritmo, const string& nomeAlgoritmo) {
    char tipo;
    cout << "\n--- Testes para " << nomeAlgoritmo << " ---" << endl;
    cout << "Tipo de entrada:" << endl;
    cout << "c - Crescente" << endl;
    cout << "d - Decrescente" << endl;
    cout << "r - Random" << endl;
    cout << "t - Todos" << endl;
    cout << "Escolha: ";
    cin >> tipo;

    if (tipo != 'c' && tipo != 'd' && tipo != 'r' && tipo != 't') {
        cout << "Opcao de tipo invalida!" << endl;
        return;
    }

    vector<int> tamanhos = escolherTamanhos();
    if (tamanhos.empty()) {
        cout << "Opcao de tamanho invalida!" << endl;
        return;
    }

    if (tipo == 't') {
        for (char t_char : {'c', 'd', 'r'}) {
            for (int tamanho : tamanhos) {
                executarTeste(tamanho, t_char, algoritmo, nomeAlgoritmo);
            }
        }
    } else {
        for (int tamanho : tamanhos) {
            executarTeste(tamanho, tipo, algoritmo, nomeAlgoritmo);
        }
    }
    cout << "\nTestes para " << nomeAlgoritmo << " concluidos!" << endl;
}

// ===================== HEAPSORT E FILAS DE PRIORIDADE =====================

// Imprime o vetor em uma linha, precedido de um titulo
void imprimirVetor(const string& titulo, const vector<int>& A) {
    cout << titulo << ": ";
    for (size_t i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Pergunta a ordem (c, d ou r) e o tamanho e gera o vetor.
// Retorna um vetor vazio se a entrada for invalida.
vector<int> criarVetorDoUsuario() {
    char tipo;
    int tamanho;

    cout << "Ordem do vetor (r - Aleatorio, c - Crescente, d - Decrescente): ";
    cin >> tipo;
    cout << "Tamanho do vetor: ";
    if (!(cin >> tamanho) || tamanho <= 0) {
        limparEntrada();
        cout << "Tamanho invalido!" << endl;
        return {};
    }

    if (tipo == 'c') return gerarCrescente(tamanho);
    if (tipo == 'd') return gerarDecrescente(tamanho);
    if (tipo == 'r') return gerarRandom(tamanho);

    cout << "Ordem invalida!" << endl;
    return {};
}

// Demonstracao do HeapSort com 10 elementos (fixos ou digitados).
// Com o vetor fixo o resultado esperado e:
// CHAMADO A BUILD: 1 4 3 56 6 43 24 96 87 76
// CHAMADO O HEAPSORT: 96 87 76 56 43 24 6 4 3 1
void demonstracaoHeapSort() {
    vector<int> A = {6, 4, 3, 56, 76, 43, 24, 96, 87, 1};
    char op;

    cout << "Usar vetor fixo (f) ou digitar 10 valores (d)? ";
    cin >> op;
    if (op == 'd') {
        cout << "Digite 10 valores inteiros: ";
        for (int i = 0; i < 10; i++) {
            if (!(cin >> A[i])) {
                limparEntrada();
                cout << "Valor invalido!" << endl;
                return;
            }
        }
    }

    imprimirVetor("VETOR ORIGINAL", A);
    vector<int> heap = A;
    BUILD_MIN_HEAP(heap);
    imprimirVetor("CHAMADO A BUILD", heap);
    vector<int> ordenado = A;
    HEAPSORT_MIN(ordenado);
    imprimirVetor("CHAMADO O HEAPSORT", ordenado);
}

// Gera as instancias de todos os tamanhos na forma escolhida, ordena cada uma
// e grava os arquivos de entrada, saida e tempo em "Heap Sort/" (mesmo padrao
// dos outros algoritmos, ex.: SaidaHeapSortCrescente10.txt).
// Nao imprime os vetores, so uma mensagem de conclusao no final.
void instanciasHeapSort() {
    const vector<int> tamanhos = {10, 100, 1000, 10000, 100000, 1000000};
    char tipo;

    cout << "Forma das instancias (r - Aleatorio, c - Crescente, d - Decrescente): ";
    cin >> tipo;
    if (tipo != 'r' && tipo != 'c' && tipo != 'd') {
        cout << "Forma invalida!" << endl;
        return;
    }

    for (int tamanho : tamanhos) {
        executarTeste(tamanho, tipo, HEAPSORT_MIN, "Heap Sort", false);
    }
    cout << "HEAPSORT_MIN concluido! Arquivos de entrada, saida e tempo gravados na pasta \"Heap Sort\"." << endl;
}

// Opcao 1: demonstracao com 10 elementos ou instancias com arquivos
void opcaoHeapSort() {
    int modo;
    cout << "\n1 - Demonstracao com vetor de 10 elementos" << endl;
    cout << "2 - Instancias de 10 a 1.000.000 (arquivos de entrada, saida e tempo)" << endl;
    cout << "Escolha: ";
    if (!(cin >> modo)) {
        limparEntrada();
        modo = -1;
    }

    if (modo == 1) {
        demonstracaoHeapSort();
    } else if (modo == 2) {
        instanciasHeapSort();
    } else {
        cout << "Opcao invalida!" << endl;
    }
}

// Opcao 2: monta o heap e mostra o minimo
void opcaoHeapMinimum() {
    vector<int> A = criarVetorDoUsuario();
    if (A.empty()) return;
    BUILD_MIN_HEAP(A);
    imprimirVetor("HEAP", A);
    cout << "MINIMO: " << HEAP_MINIMUM(A) << endl;
}

// Opcao 3: monta o heap e extrai o minimo
void opcaoHeapExtractMin() {
    vector<int> A = criarVetorDoUsuario();
    if (A.empty()) return;
    BUILD_MIN_HEAP(A);
    imprimirVetor("HEAP ANTES DA EXTRACAO", A);
    int minimo = HEAP_EXTRACT_MIN(A);
    cout << "MINIMO EXTRAIDO: " << minimo << endl;
    imprimirVetor("HEAP DEPOIS DA EXTRACAO", A);
}

// Opcao 4: monta o heap e atribui 1000 na posicao escolhida.
// O nome e do enunciado (heap maximo); como o heap e minimo,
// a restauracao usa a logica do heap minimo (MIN_HEAPIFY).
void opcaoHeapIncreaseKey() {
    vector<int> A = criarVetorDoUsuario();
    if (A.empty()) return;
    BUILD_MIN_HEAP(A);
    imprimirVetor("HEAP ANTES", A);

    int posicao;
    cout << "Posicao para receber 1000 (0 a " << A.size() - 1 << "): ";
    if (!(cin >> posicao) || posicao < 0 || posicao >= (int)A.size()) {
        limparEntrada();
        cout << "Posicao invalida!" << endl;
        return;
    }

    HEAP_INCREASE_KEY(A, posicao, 1000);
    imprimirVetor("HEAP DEPOIS", A);
}

// Opcao 5: monta o heap e insere 1000.
// O nome e do enunciado (heap maximo); como o heap e minimo,
// a insercao sobe o elemento enquanto ele for menor que o pai.
void opcaoMaxHeapInsert() {
    vector<int> A = criarVetorDoUsuario();
    if (A.empty()) return;
    BUILD_MIN_HEAP(A);
    imprimirVetor("HEAP ANTES", A);
    MAX_HEAP_INSERT(A, 1000);
    imprimirVetor("HEAP DEPOIS", A);
}

// Menu do trabalho de HeapSort e Filas de Prioridade (tudo minimo).
// As opcoes 1 a 5 voltam a este menu; SAIR (0) encerra o programa.
void menuHeap() {
    int opcao;

    do {
        cout << "\n===== HEAPSORT E FILAS DE PRIORIDADE (MINIMO) =====" << endl;
        cout << "1 - HEAPSORT_MIN" << endl;
        cout << "2 - HEAP_MINIMUM" << endl;
        cout << "3 - HEAP_EXTRACT_MIN" << endl;
        cout << "4 - HEAP_INCREASE_KEY" << endl;
        cout << "5 - MAX_HEAP_INSERT" << endl;
        cout << "0 - SAIR" << endl;
        cout << "Escolha uma opcao: ";

        if (!(cin >> opcao)) {
            limparEntrada();
            opcao = -1;  // cai no default
        }

        switch (opcao) {
            case 1:
                opcaoHeapSort();
                break;
            case 2:
                opcaoHeapMinimum();
                break;
            case 3:
                opcaoHeapExtractMin();
                break;
            case 4:
                opcaoHeapIncreaseKey();
                break;
            case 5:
                opcaoMaxHeapInsert();
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida! Tente novamente" << endl;
                break;
        }
    } while (opcao != 0);
}

//Selecao de Algoritmo
int main() {
    int opcao;

    do {
        cout << "\n========= MENU DE ALGORITMOS DE ORDENACAO =========" << endl;
        cout << "1 - Insertion Sort" << endl;
        cout << "2 - Bubble Sort" << endl;
        cout << "3 - Selection Sort" << endl;
        cout << "4 - Shell Sort" << endl;
        cout << "5 - Merge Sort" << endl;
        cout << "6 - Quick Sort Versao 1" << endl;
        cout << "7 - Quick Sort Versao 2" << endl;
        cout << "8 - HeapSort e Filas de Prioridade" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";

        if (!(cin >> opcao)) {
            limparEntrada();
            opcao = -1;  // cai no default
        }

        switch (opcao) {
            case 1:
                executarMenuDeTestes(insertionSort, "Insertion Sort");
                break;
            case 2:
                executarMenuDeTestes(BubbleSort, "Bubble Sort");
                break;
            case 3:
                executarMenuDeTestes(SelectionSort, "Selection Sort");
                break;
            case 4:
                executarMenuDeTestes(ShellSort, "Shell Sort");
                break;
            case 5:
                executarMenuDeTestes(MergeSort, "Merge Sort");
                break;
            case 6:
                executarMenuDeTestes(QuickSortV1, "Quick Sort V1");
                break;
            case 7:
                executarMenuDeTestes(QuickSortV2, "Quick Sort V2");
                break;
            case 8:
                // O SAIR do menu do heap encerra o programa (como pede o enunciado)
                menuHeap();
                opcao = 0;
                cout << "Programa finalizado" << endl;
                break;
            case 0:
                cout << "Programa finalizado" << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente" << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}