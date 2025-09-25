/*

Criado em: 25/09/2025 por Eduardo
Responsabilidade de: Eduardo
Finalizado em: --/--/2025

# Visão geral:
Arquivo .cpp complementar para implementar as funções, classes e 
estruturas e utilizar as contantes e variáveis globais antes protótipadas no
header: "game.hpp"

# Uso:
Para ver os detalhes do uso das funções e métodos, leia a documentação em
formato Doxygen acima do cabeçalho da função

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include "../include/game.hpp"

// ================================< Funções >=================================

/// @brief Inicia um jogo para o usuário, e calcula a pontuação no fim
/// @return Pontuação ganha pelo jogador nesse jogo
int play(){
    int points = 0;
    std::cout << "Jogo em implementacao, volte depois!\n";
    std::cout << "Pontuação ganha durante esse jogo: " << points << ".\n\n";

    std::cout << "-- pressione 'Enter' para voltar ao menu.\n";
    std::cout << "> " << std::endl;
    std::cin; // Espera o usuário pressionar Enter para finalizar o jogo

    return points;
}