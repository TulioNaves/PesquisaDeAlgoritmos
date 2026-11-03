#ifndef TESTE_H
#define TESTE_H

#include <vector>
#include <functional>
#include <string>

void executarTeste(int tamanho, char tipo, std::function<void(std::vector<int>&)> algoritmo, const std::string& nomeAlgoritmo);

#endif //TESTE_H