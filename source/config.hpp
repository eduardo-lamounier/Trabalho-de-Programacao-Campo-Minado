/*

Criado em: 27/08/2025 por Eduardo Lamounier Miranda
Finalizado em: --/--/2025

Um header com as funções de inicialização dos dados, configuração das opções do
jogo, além da função geral que cria o menu do jogo.

*/

#pragma once

#define MIN_WIDTH_ND_HEIGHT 5
#define MAX_WIDTH_ND_HEIGHT 40

#define MAX_BOMBS_PERCENTAGE_OF_AREA 80

class GameConfig{
    private:
        int width, height;
        int totalBombs;
        int noBombsRegion;
    public: 
        int get(char *property);

        void inputSettings();
};

void menu();