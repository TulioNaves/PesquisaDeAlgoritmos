#ifndef TESTE_H
#define TESTE_H

#include <vector>
#include <functional>
#include <string>

// mostrarResultado = false nao imprime a linha de resultado de cada teste
void executarTeste(int tamanho, char tipo, std::function<void(std::vector<int>&)> algoritmo, const std::string& nomeAlgoritmo, bool mostrarResultado = true);

#endif //TESTE_H