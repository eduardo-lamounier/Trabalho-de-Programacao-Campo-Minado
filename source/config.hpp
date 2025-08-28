/*

Criado em: 27/08/2025 por Eduardo
Finalizado em: --/--/2025

Um header com as funções de inicialização dos dados, configuração das opções do
jogo, além da função geral que cria o menu do jogo.

*/

#pragma once

#define MIN_WIDTH_ND_HEIGHT 5
#define MAX_WIDTH_ND_HEIGHT 40

#define MAX_BOMBS_PERCENTAGE_OF_AREA 80

/// @brief Classe que armazena as principais propriedades do programa, além
///        de armazenar métodos para configuração
class GameConfig{
    private:
        int Width, Height;
        int TotalBombs;
        int NoBombsRegion;
    public: 
        int Get(char *property);

        void InputSettings();
};

void menu();