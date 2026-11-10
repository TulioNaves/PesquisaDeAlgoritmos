cmake_minimum_required(VERSION 3.20)
project(pesquisadealgoritmos)

# <filesystem> (usado em Arquivo.cpp) exige C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
include_directories(src/Tools)

add_executable(pesquisadealgoritmos
        src/Tools/Arquivo.cpp
        src/Tools/Arquivo.h
        src/Tools/Gerador.cpp
        src/Tools/Gerador.h
        src/Tools/Tempo.cpp
        src/Tools/Tempo.h
        src/Tools/Teste.cpp
        src/Tools/Teste.h
        src/BubbleSort.cpp
        src/BubbleSort.h
        src/InsertionSort.cpp
        src/InsertionSort.h
        src/main.cpp
        src/MergeSort.cpp
        src/MergeSort.h
        src/QuickSort.cpp
        src/QuickSort.h
        src/SelectionSort.cpp
        src/SelectionSort.h
        src/ShellSort.cpp
        src/ShellSort.h)

# Pasta onde ficam "Bubble Sort/", "Insertion Sort/" etc. (raiz do projeto),
# para os arquivos nao irem parar dentro de cmake-build-debug
target_compile_definitions(pesquisadealgoritmos PRIVATE PASTA_PROJETO="${CMAKE_SOURCE_DIR}")


# Aumenta a pilha do executavel para 1 GB. O Quick Sort Versao 1 faz ate n chamadas
# recursivas aninhadas em vetores crescentes e decrescentes, e com a pilha padrao
# do Windows (1 MB) o programa quebra a partir de uns 30.000 elementos.
if(MSVC)
    target_link_options(pesquisadealgoritmos PRIVATE "/STACK:1073741824")
elseif(MINGW)
    target_link_options(pesquisadealgoritmos PRIVATE "-Wl,--stack,1073741824")
endif()
