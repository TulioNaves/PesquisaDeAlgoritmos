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