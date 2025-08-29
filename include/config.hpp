/*

Criado em: 27/08/2025 por Eduardo
Finalizado em: --/--/2025

# Visão geral:
Um header com as funções de inicialização dos dados, configuração das opções do
jogo, além da função geral que cria o menu do jogo.

# Uso:
Para ver os detalhes do uso das funções e métodos, passe o mouse por cima e
leia a documentação

*/

#pragma once

// ===================< Bibliotecas, headers e namespaces >====================

// ------------------------------/ Bibliotecas /-------------------------------
#include<iostream>
#include<string>

// ===========================< Constantes globais >===========================

// Quantidade mínima e máxima de linhas e colunas:
#define MIN_WIDTH_ND_HEIGHT 5
#define MAX_WIDTH_ND_HEIGHT 40

// Porcentagem mínima e máxima de bombas por unidade de área:
#define MIN_BOMBS_PER_AREA 0.20f
#define MAX_BOMBS_PER_AREA 0.80f

// Porcentagem mínima e máxima de espaço reservado sem bombas:
#define MIN_NO_BOMBS_REGION 3
#define MAX_NO_BOMBS_REGION_PER_TOTAL_AREA 0.15f

// ================================< Classes >=================================

/// @brief Classe estática que armazena as principais propriedades do programa, além
///        de armazenar métodos para configuração
class GameConfig{
    private:
        static int Width, Height; // Quantidade de colunas e linhas, respectivamente
        static int TotalBombs;
        static int NoBombsRegion;
    
        /* Construtor privado (Classe estática) */ GameConfig(){};
    public: 
        static int Get(const std::string& property);

        static void InputSettings();
};

// ================================< Funções >=================================

void menu();