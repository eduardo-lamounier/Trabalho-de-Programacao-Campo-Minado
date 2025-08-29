/*

# Visão geral:
Arquivo .cpp complementar para implementar as funções, constantes, classes e 
estruturas antes prototipadas no header "config.hpp"

# Uso:
Para ver os detalhes do uso das funções e métodos, passe o mouse por cima e
leia a documentação

*/

#include "../include/config.hpp"

// ========================< Propriedades de classes >=========================

// ------------------------------/ GamesConfig /-------------------------------

int GameConfig::Width = MIN_WIDTH_ND_HEIGHT;
int GameConfig::Height = MIN_WIDTH_ND_HEIGHT;
int GameConfig::TotalBombs = MIN_BOMBS_PER_AREA * (/* Area */ MIN_WIDTH_ND_HEIGHT * MIN_WIDTH_ND_HEIGHT);
int GameConfig::NoBombsRegion = MIN_NO_BOMBS_REGION;

// ===========================< Métodos de classes >===========================

// ------------------------------/ GamesConfig /-------------------------------

/// @brief Acessa uma propriedade expecifica da classe GameConfig
/// @param property Uma referência a uma string, cujo texto corresponde
///                 ao nome da propriedade a ser acessada
/// @return Retorna o valor inteiro da propriedade corespondente
/// @note Lança uma exceção para uma string inválida
int GameConfig::Get(std::string& property){
    if(property == "Width"){
        return Width;
    }else if(property == "Height"){
        return Height;
    }else if(property == "TotalBombs"){
        return TotalBombs;
    }else if(property == "NoBombsRegion"){
        return NoBombsRegion;
    }else{
        throw("Argumento inválido passado para a função: int GameConfig::get(std::string property). Digite uma string correspondente a alguma propriedade válida da classe GameConfig.\n");
    }
}

/// @brief Faz o input das configurações escolhidas pelo usuário, e armazena na
///        classe GameConfig
void GameConfig::InputSettings(){
    // (Lógica aqui)
}

// ==============================< Funções >===================================

/// @brief Carrega o menu, mostrando as primeiras opções para o usuário
void menu(){
    // (Lógica aqui)
}