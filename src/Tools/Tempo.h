#ifndef TEMPO_H
#define TEMPO_H

#include <vector>
#include <functional>

double medirTempo(std::function<void(std::vector<int>&)> algoritmo, std::vector<int>& vetor);

#endif //TEMPO_H