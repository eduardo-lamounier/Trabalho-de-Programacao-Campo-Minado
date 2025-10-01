/*

Criado em: 13/09/2025 por Eduardo
Responsabilidade de: Eduardo
Finalizado em: 13/09/2025

# Visão geral:
Header que incluí TODAS as bibliotecas padrão de C++ para facilitar a inclusão 
nos códigos fonte (na pasta /source) e nos outros headers (da pasta desse
arquivo: /include)

# Uso:
    * Incluir em todos os códigos fonte (pasta /source) que não incluírem outro
header: "../include/common.hpp"
    * Incluir em todos os headers da pasta desse arquivo (pasta /include):
"common.hpp" (dessa vez sem o '../' porque já estão na pasta desse arquivo)

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#pragma once

// Eu (Eduardo) peguei as bibliotecas pelo Deepseek para facilitar (completar 
// com mais bibliotecas se estiver faltando)

// Inclusões comentadas e marcadas com asterisco (*) são aquelas que não foram
// reconhecidas (só existem do C++17 em diante)

// Além disso, incluí aqui definições para tipos que vão ou podem ser bastante
// utilizados durante o projeto (fim do arquivo)

// >> Containers:
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

// >> I/O e Streams:
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <iomanip>

// >> Strings:
#include <string>
//* #include <string_view>

// >> Algoritmos e Utilitários:
#include <algorithm>
#include <functional>
#include <utility>
#include <tuple>
//* #include <optional>
//* #include <variant>
//* #include <any>

// >> Memória:
#include <memory>

// >> Tipos Numéricos:
#include <cmath>
#include <complex>
#include <random>
#include <numeric>
#include <limits>

// >> Tempo e Data:
#include <chrono>
#include <ctime>

// >> Threads e Concorrência:
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <condition_variable>

// >> Outros:
#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
//* #include <filesystem>
#include <regex>

// >> TIPOS:
namespace cmm {
    using index = unsigned int;

    template<typename T>
    using matrix = std::vector<std::vector<T>>;
}