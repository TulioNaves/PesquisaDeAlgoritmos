# Análise de Desempenho em Algoritmos de Ordenação

Trabalho da disciplina **SIN213 – Projeto de Algoritmos** (UFV – Campus Rio Paranaíba), ministrada pelo Prof. Pedro Moisés de Souza.

**Autor:** Túlio José Oliveira Naves – 8780

O projeto implementa em C++ cinco algoritmos de ordenação e mede o tempo de execução de cada um em vetores de 10 a 1.000.000 de elementos, com três tipos de entrada. Os resultados e a análise de complexidade estão no relatório em LaTeX.

## Algoritmos

| Algoritmo      | Melhor caso   | Caso médio    | Pior caso     | Memória extra |
|----------------|---------------|---------------|---------------|---------------|
| Insertion Sort | O(n)          | O(n²)         | O(n²)         | O(1)          |
| Bubble Sort    | O(n²)         | O(n²)         | O(n²)         | O(1)          |
| Selection Sort | O(n²)         | O(n²)         | O(n²)         | O(1)          |
| Shell Sort     | O(n log n)    | subquadrático | O(n²)         | O(1)          |
| Merge Sort     | O(n log n)    | O(n log n)    | O(n log n)    | O(n)          |

O Shell Sort usa a sequência de *gaps* n/2, n/4, ..., 1.

## Estrutura

```
├── CMakeLists.txt
├── src/
│   ├── main.cpp                 # menu interativo
│   ├── BubbleSort.cpp/.h
│   ├── InsertionSort.cpp/.h
│   ├── MergeSort.cpp/.h
│   ├── SelectionSort.cpp/.h
│   ├── ShellSort.cpp/.h
│   └── Tools/
│       ├── Gerador.cpp/.h       # gera vetores crescentes, decrescentes e aleatórios
│       ├── Arquivo.cpp/.h       # grava vetores e tempos em .txt
│       ├── Tempo.cpp/.h         # mede o tempo de execução
│       └── Teste.cpp/.h         # executa um teste completo
├── <Algoritmo>/Arquivos de Tempo/   # tempos medidos (Crescente, Decrescente, Random)
└── RelatorioPesquisaDeAlgoritmos/   # relatório em LaTeX
```

## Como compilar e executar

É preciso ter CMake 3.20 ou mais recente e um compilador com suporte a C++17 (GCC/MinGW, Clang ou MSVC).

```bash
cmake -S . -B build
cmake --build build
./build/pesquisadealgoritmos
```

No CLion, basta abrir a pasta do projeto e rodar o alvo `pesquisadealgoritmos`.

O programa abre um menu para escolher:

1. o algoritmo;
2. o tipo de entrada: `c` (crescente), `d` (decrescente), `r` (aleatória) ou `t` (todas);
3. o tamanho do vetor: 10, 100, 1.000, 10.000, 100.000, 1.000.000 ou todos.

Para cada teste são gravados três arquivos na pasta do algoritmo, na raiz do projeto, qualquer que seja o diretório de onde o programa é executado:

- `Arquivos de Entrada/<Tipo>/` — vetor gerado;
- `Arquivos de Saida/<Tipo>/` — vetor ordenado;
- `Arquivos de Tempo/<Tipo>/` — tamanho e tempo de execução, em segundos.

> Os arquivos de entrada e saída não estão no repositório porque ocupam cerca de 50 MB por algoritmo. Eles são recriados quando o programa é executado.

## Resultados (1.000.000 de elementos)

Tempos em segundos:

| Algoritmo      | Crescente | Decrescente | Aleatória |
|----------------|----------:|------------:|----------:|
| Insertion Sort | 0,005     | 2.164,840   | 1.086,290 |
| Bubble Sort    | 1.474,120 | 3.913,080   | 3.954,730 |
| Selection Sort | 1.365,660 | 1.561,630   | 1.658,270 |
| Shell Sort     | 0,099     | 0,129       | 0,461     |
| Merge Sort     | 0,155     | 0,168       | 0,292     |

Principais conclusões:

- Os algoritmos quadráticos (Bubble, Insertion e Selection) levaram de 18 a 66 minutos para ordenar um milhão de elementos aleatórios. O Shell Sort e o Merge Sort levaram menos de meio segundo.
- O **Merge Sort** foi o mais rápido com entrada aleatória e teve tempos parecidos nos três cenários, mas precisa de um vetor auxiliar de tamanho n.
- O **Shell Sort** foi o mais rápido com entradas crescente e decrescente, sem usar memória extra.
- O **Insertion Sort** é o mais sensível à ordem dos dados: de 0,005 s no melhor caso a 2.164 s no pior.
- Até 1.000 elementos, os cinco algoritmos terminaram em menos de 0,005 s.

A análise completa, com tabelas de custo, testes de mesa, a recorrência do Merge Sort e os gráficos, está no relatório.

## Relatório

O relatório está em [`RelatorioPesquisaDeAlgoritmos/`](RelatorioPesquisaDeAlgoritmos). O arquivo principal é `Relatório_Corpo.tex`. Para gerar o PDF, compile-o com `pdflatex` (ou pelo Overleaf):

```bash
cd RelatorioPesquisaDeAlgoritmos
pdflatex Relatório_Corpo.tex
pdflatex Relatório_Corpo.tex   # segunda vez para montar o sumário
```
