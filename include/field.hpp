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

// ================================< Classes >=================================

class FieldSquare {
private:
    // ---------------------/ Propriedades privadas /----------------------

    bool Shown; // Representa se o valor dessa posição é visto ou não pelo
    // jogador
    bool Flaged; // Representa se o jogador colocou uma bandeira na posição
    // atual ou não
    bool Reserved;  // Representa se o quadrado está sendo reservado para uma
    // área que não poderá ter bombas
    int BombsNearby; // Representa quantas bombas há ao redor dessa posição
    // (-1 se for uma posição de bomba)
public:
    // ------------------------/ Métodos públicos /------------------------

    int GetBombsNearby();

    bool BeingShown();

    bool hasFlag();

    void SetBombsNearby(const int bombsNearby);

    void PlaceBomb();

    void PlaceFlag();

    void RemoveFlag();

    void Reveal();

    bool ReservedSquare();

    void ReserveSquare();

    FieldSquare();
};

class Field {
private:
    // ---------------------/ Propriedades privadas /----------------------

    static cmm::matrix<FieldSquare> Data; // Armazena a matriz do campo minado

    // ------------------------/ Métodos privados /------------------------

    /*Construtor privado (Classe estática) */ Field();

    static void ReserveNoBombRegion();
public:
    // ------------------------/ Métodos públicos /------------------------

    static FieldSquare &At(const cmm::index row, const cmm::index col);

    static void Generate();

    static void Display();

    static void RevealAll();

    static int IsRevealed();
};