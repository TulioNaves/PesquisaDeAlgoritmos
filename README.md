# Análise de Desempenho em Algoritmos de Ordenação

Trabalho da disciplina **SIN213 – Projeto de Algoritmos** (UFV – Campus Rio Paranaíba), ministrada pelo Prof. Pedro Moisés de Souza.

**Autor:** Túlio José Oliveira Naves – 8780

O projeto implementa em C++ sete algoritmos de ordenação (cinco clássicos e duas versões do Quick Sort) e mede o tempo de execução de cada um em vetores de 10 a 1.000.000 de elementos, com três tipos de entrada. Os resultados e a análise de complexidade estão no relatório em LaTeX.

## Algoritmos

| Algoritmo      | Melhor caso   | Caso médio    | Pior caso     | Memória extra |
|----------------|---------------|---------------|---------------|---------------|
| Insertion Sort | O(n)          | O(n²)         | O(n²)         | O(1)          |
| Bubble Sort    | O(n²)         | O(n²)         | O(n²)         | O(1)          |
| Selection Sort | O(n²)         | O(n²)         | O(n²)         | O(1)          |
| Shell Sort     | O(n log n)    | subquadrático | O(n²)         | O(1)          |
| Merge Sort     | O(n log n)    | O(n log n)    | O(n log n)    | O(n)          |
| Quick Sort V1  | O(n log n)    | O(n log n)    | O(n²)         | O(log n) a O(n) (pilha) |
| Quick Sort V2  | O(n log n)    | O(n log n)    | O(n²)         | O(log n) a O(n) (pilha) |

O Shell Sort usa a sequência de *gaps* n/2, n/4, ..., 1.

As duas versões do Quick Sort usam o mesmo particionamento (estilo Sedgewick, com os índices `i` e `j` andando um em direção ao outro). A diferença está na escolha do pivô:

- **Versão 1:** o pivô é o primeiro elemento do trecho;
- **Versão 2:** o pivô é a mediana de três (primeiro, meio e último elementos), levada para a primeira posição antes de particionar.

## Estrutura

```
├── CMakeLists.txt
├── src/
│   ├── main.cpp                 # menu interativo
│   ├── BubbleSort.cpp/.h
│   ├── InsertionSort.cpp/.h
│   ├── MergeSort.cpp/.h
│   ├── QuickSort.cpp/.h         # Quick Sort V1 e V2
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

> **Pilha de 1 GB:** o Quick Sort V1 chega a fazer n chamadas recursivas aninhadas com entradas crescentes e decrescentes, e com a pilha padrão do Windows (1 MB) o programa quebra a partir de uns 30.000 elementos. Por isso o `CMakeLists.txt` aumenta a pilha do executável para 1 GB (`/STACK` no MSVC e `-Wl,--stack` no MinGW). Em Linux/macOS, use `ulimit -s unlimited` antes de executar, se necessário.

O programa abre um menu para escolher:

1. o algoritmo (1 a 5 para os clássicos, 6 para o Quick Sort V1 e 7 para o Quick Sort V2);
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
| Insertion Sort | 0,004     | 2.164,840   | 1.086,290 |
| Bubble Sort    | 1.474,120 | 3.913,080   | 3.954,730 |
| Selection Sort | 1.365,660 | 1.561,630   | 1.658,270 |
| Shell Sort     | 0,099     | 0,129       | 0,461     |
| Merge Sort     | 0,155     | 0,168       | 0,292     |
| Quick Sort V1  | 906,297   | 1.014,890   | 0,165     |
| Quick Sort V2  | 0,059     | 281,275     | 0,177     |

Principais conclusões:

- Os algoritmos quadráticos (Bubble, Insertion e Selection) levaram de 18 a 66 minutos para ordenar um milhão de elementos aleatórios. O Shell Sort e o Merge Sort levaram menos de meio segundo.
- O **Merge Sort** foi o mais rápido com entrada aleatória e teve tempos parecidos nos três cenários, mas precisa de um vetor auxiliar de tamanho n.
- O **Shell Sort** foi o mais rápido com entradas crescente e decrescente, sem usar memória extra.
- O **Insertion Sort** é o mais sensível à ordem dos dados: de 0,004 s no melhor caso a 2.164 s no pior.
- O **Quick Sort V1** foi o mais rápido de todos com entrada aleatória (0,165 s), mas com entradas crescente e decrescente o pivô no primeiro elemento gera partições totalmente desbalanceadas e o tempo cresce de forma quadrática: cerca de 15 a 17 minutos para um milhão de elementos.
- O **Quick Sort V2** (mediana de três) resolveu o caso crescente, que virou o mais rápido de todos os testes (0,059 s), e manteve o bom desempenho com entrada aleatória. Com entrada decrescente, porém, ainda apresentou comportamento quadrático (281 s), embora cerca de 3,6 vezes mais rápido que a versão 1.
- Até 1.000 elementos, os sete algoritmos terminaram em menos de 0,005 s.

A análise completa, com tabelas de custo, testes de mesa, a recorrência do Merge Sort e os gráficos, está no relatório.

## Relatório

O relatório está em [`RelatorioPesquisaDeAlgoritmos/`](RelatorioPesquisaDeAlgoritmos). O arquivo principal é `Relatório_Corpo.tex`. Para gerar o PDF, compile-o com `pdflatex` (ou pelo Overleaf):

```bash
cd RelatorioPesquisaDeAlgoritmos
pdflatex Relatório_Corpo.tex
pdflatex Relatório_Corpo.tex   # segunda vez para montar o sumário
```
