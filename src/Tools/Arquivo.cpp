//
// Created by tjona on 17/09/2026.
#include "Arquivo.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

// Cria a pasta e todas as pastas intermediarias que ainda nao existirem
void criarDiretorio(const string& nome) {
    error_code erro;
    filesystem::create_directories(nome, erro);
    if (erro) {
        cout << "Nao foi possivel criar a pasta: " << nome << " (" << erro.message() << ")" << endl;
    }
}

void salvarArquivo(const vector<int>& vetor, string nome) {
    ofstream arquivo(nome);
    if (arquivo.is_open()) {
        arquivo << vetor.size() << endl;
        for (size_t i = 0; i < vetor.size(); i++) {
            arquivo << vetor[i] << endl;
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo para escrita: " << nome << endl;
    }
}

void salvarTempo(const string& nome, int tamanho, double tempo) {
    ofstream arquivo(nome);
    arquivo << tamanho << endl;
    arquivo << tempo << endl;
    arquivo.close();
}