/*

Criado em: 24/09/2025 por Eduardo
Responsabilidade de: Heitor
Finalizado em: --/--/2025

# Visão geral:
Um header com o protótipo das funções de geração, atualização e exibição do
campo minado

# Uso:
Para ver os detalhes do uso das funções e métodos, passe o mouse por cima e
leia a documentação escrita no arquivo .cpp

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#pragma once

// ===================< Bibliotecas, headers e namespaces >====================

// ------------------------------/ Bibliotecas /-------------------------------

#include "common.hpp" // Inclusão de todas as bibliotecas padrão de C++

#include "config.hpp" // Inclusão da classe com as configurações do campo
                      // minado

// =================================< Tipos >==================================

using index = unsigned int; // Esse tipo se refere a uma posição de array ou
                            // matriz

template<typename T>
using Matrix = std::vector<std::vector<T>>;

// ================================< Classes >=================================

class FieldSquare {
    private:
        bool Shown; // Representa se o valor dessa posição é visto ou não pelo
                    // jogador
        int BombsNearby; // Representa quantas bombas há ao redor dessa posição
                         // (-1 se for uma posição de bomba)
    public:
        // ------------------------/ Métodos públicos /------------------------
        
        int GetBombsNearby();

        bool BeingShown();
        
        void SetBombsNearby(const int bombsNearby);
        
        void PlaceBomb();

        void Reveal();

        FieldSquare();
};

class Field {
    private:
        // ---------------------/ Propriedades privadas /----------------------

        static Matrix<FieldSquare> Data; // Armazena a matriz do campo minado
    
        // ------------------------/ Métodos privados /------------------------
        
        /*Construtor privado (Classe estática) */ Field();
    public:
        // ------------------------/ Métodos públicos /------------------------

        static FieldSquare& At(const index row, const index col);

        static void Generate();
        
        static void Display();
};