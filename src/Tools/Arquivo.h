#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <vector>
#include <string>


void criarDiretorio(const std::string& nome);
void salvarArquivo(const std::vector<int>& vetor, std::string nome);
void salvarTempo(const std::string& nome, int tamanho, double tempo);

#endif //ARQUIVO_H