/*

Criado em: 27/08/2025 por Eduardo
Finalizado em: --/--/2025

Um header com as funções de inicialização dos dados, configuração das opções do
jogo, além da função geral que cria o menu do jogo.

*/

#pragma once

// Quantidade mínima e máxima de linhas e colunas:
#define MIN_WIDTH_ND_HEIGHT 5
#define MAX_WIDTH_ND_HEIGHT 40

// Porcentagem máxima de bombas por unidade de área:
#define MAX_BOMBS_PERCENTAGE_OF_AREA 80

/// @brief Classe estática que armazena as principais propriedades do programa, além
///        de armazenar métodos para configuração
class GameConfig{
    private:
        static int Width, Height;
        static int TotalBombs;
        static int NoBombsRegion;
    
        /* Construtor privado (Classe estática) */ GameConfig(){};
    public: 
        static int Get(char *property);

        static void InputSettings();
};

void menu();