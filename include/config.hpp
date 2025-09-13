/*

Criado em: 27/08/2025 por Eduardo
Responsabilidade de: Miguel
Finalizado em: --/--/2025

# Visão geral:
Um header com as funções de inicialização dos dados, configuração das opções do
jogo, além da função geral que cria o menu do jogo.

# Uso:
Para ver os detalhes do uso das funções e métodos, passe o mouse por cima e
leia a documentação escrita no arquivo .cpp

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#pragma once

// ===================< Bibliotecas, headers e namespaces >====================

// ------------------------------/ Bibliotecas /-------------------------------

#include "common.hpp" // Inclusão de todas as bibliotecas padrão de C++

// ===========================< Constantes globais >===========================

// Quantidade mínima e máxima de linhas e colunas:
#define MIN_WIDTH_ND_HEIGHT 5
#define MAX_WIDTH_ND_HEIGHT 40

// Porcentagem mínima e máxima de bombas por unidade de área:
#define MIN_BOMBS_PER_AREA 0.30f
#define MAX_BOMBS_PER_AREA 0.85f

#define MIN_NO_BOMBS_REGION 9 // Quantidade mínima de quadrados reservados sem
                              // bombas
#define MAX_NO_BOMBS_REGION_PER_TOTAL_AREA 0.15f // Porcentagem máxima de 
                                                 // espaço reservado sem bombas

// ================================< Classes >=================================

/// @brief Classe estática que armazena as principais propriedades do programa,
///        além de armazenar métodos para configuração
class GameConfig{
    private:
        // ---------------------/ Propriedades privadas /----------------------

        static int Width, Height; // Quantidade de colunas e linhas, 
                                  // respectivamente
        static int TotalBombs;
        static int NoBombsRegion;
    
        // ------------------------/ Métodos privados /------------------------

        /* Construtor privado (Classe estática): */ GameConfig();
    public:
        // ------------------------/ Métodos públicos /------------------------

        static int Get(std::string property); // Acessa as propriedades
                                              // privadas da classe
                                              // (encapsulação)

        static void InputSettings(); // Configura as propriedades da classe de
                                     // acordo com a leitura do input do
                                     // usuário
};

// ================================< Funções >=================================

// [...]