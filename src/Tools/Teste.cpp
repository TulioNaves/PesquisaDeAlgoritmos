//
// Created by tjona on 17/09/2026.
#include "Teste.h"
#include "Gerador.h"
#include "Arquivo.h"
#include "Tempo.h"
#include <iostream>

using namespace std;

void executarTeste(int tamanho, char tipo, function<void(vector<int>&)> algoritmo, const string& nomeAlgoritmo) {
    vector<int> vetor;
    string tipoNome;

    if (tipo == 'c') {
        vetor = gerarCrescente(tamanho);
        tipoNome = "Crescente";
    } else if (tipo == 'd') {
        vetor = gerarDecrescente(tamanho);
        tipoNome = "Decrescente";
    } else if (tipo == 'r') {
        vetor = gerarRandom(tamanho);
        tipoNome = "Random";
    } else {
        return;
    }

    // Cada algoritmo tem sua propria pasta raiz (ex: "Bubble Sort/")
    string pastaRaiz = string(PASTA_PROJETO) + "/" + nomeAlgoritmo;
    criarDiretorio(pastaRaiz);

    // Nome sem espacos para usar dentro do nome dos arquivos (ex: "BubbleSort")
    string nomeArquivo;
    for (char c : nomeAlgoritmo) {
        if (c != ' ') nomeArquivo += c;
    }

    string pastaEntrada = pastaRaiz + "/Arquivos de Entrada";
    string pastaSaida = pastaRaiz + "/Arquivos de Saida";
    string pastaTempo = pastaRaiz + "/Arquivos de Tempo";

    criarDiretorio(pastaEntrada);
    criarDiretorio(pastaSaida);
    criarDiretorio(pastaTempo);

    criarDiretorio(pastaEntrada + "/" + tipoNome);
    criarDiretorio(pastaSaida + "/" + tipoNome);
    criarDiretorio(pastaTempo + "/" + tipoNome);

    string nomeEntrada = pastaEntrada + "/" + tipoNome + "/Entrada" + tipoNome + to_string(tamanho) + ".txt";
    salvarArquivo(vetor, nomeEntrada);

    vector<int> vetorOrdenado = vetor;
    double tempo = medirTempo(algoritmo, vetorOrdenado);

    string nomeSaida = pastaSaida + "/" + tipoNome + "/Saida" + nomeArquivo + tipoNome + to_string(tamanho) + ".txt";
    salvarArquivo(vetorOrdenado, nomeSaida);

    string nomeTempo = pastaTempo + "/" + tipoNome + "/Tempo" + nomeArquivo + tipoNome + to_string(tamanho) + ".txt";
    salvarTempo(nomeTempo, tamanho, tempo);

    cout << "Algoritmo: " << nomeAlgoritmo << " | Tipo: " << tipoNome << " | Tamanho: " << tamanho << " | Tempo: " << tempo << "s" << endl;
}