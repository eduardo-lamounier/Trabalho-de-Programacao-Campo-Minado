/*

Criado em: 15/09/2025 por Eduardo
Responsabilidade de: Eduardo
Finalizado em: 04/11/2025

# Visão geral:
Um header com o protótipo das funções do jogo: comandos do jogador, cálculo da
pontuação etc

# Uso:
Para ver os detalhes do uso das funções e métodos, passe o mouse por cima e
leia a documentação escrita no arquivo .cpp

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#pragma once

// ===================< Bibliotecas, headers e namespaces >====================

// ------------------------------/ Bibliotecas /-------------------------------

#include "common.hpp" // Inclusão de todas as bibliotecas padrão de C++

#include "field.hpp" // Inclusão do header de geração do campo minado

// ================================< Funções >=================================

int play();

// ================================< Classes >=================================

class Commands {
private:
    Commands() = delete;
public:
    static void List();

    static bool Dig(cmm::index row, cmm::index col);

    static void ToggleFlag(cmm::index row, cmm::index col);

    static void ClearConsole();
};