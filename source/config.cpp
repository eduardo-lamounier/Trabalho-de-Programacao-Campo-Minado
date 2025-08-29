/*

Arquivo .cpp complementar para implementar as funções, constantes, classes e 
estruturas antes prototipadas no header "config.hpp"

*/

#include<string>

#include "../include/config.hpp"

// ======================< Métodos da classe GameConfig >======================

/// @brief Acessa uma propriedade expecifica da classe GameConfig
/// @param property Uma referência ao início de uma string, cujo texto 
///                 corresponde ao nome da propriedade a ser acessada
/// @return Retorna o valor inteiro da propriedade corespondente
/// @note Lança uma exceção para uma string inválida
int GameConfig::Get(char *property){
    if(strcmp(property, "Width") == 0){
        return Width;
    }else if(strcmp(property, "Height") == 0){
        return Height;
    }else if(strcmp(property, "TotalBombs") == 0){
        return TotalBombs;
    }else if(strcmp(property, "NoBombsRegion") == 0){
        return NoBombsRegion;
    }else{
        throw("Argumento inválido passado para a função: int GameConfig::get(char *property). Digite uma string correspondente a alguma propriedade válida da classe GameConfig.\n");
    }
}

/// @brief Faz o input das configurações escolhidas pelo usuário, e armazena na
///        classe GameConfig
void GameConfig::InputSettings(){
    // (Lógica aqui)
}

// ================================< Menu >====================================

/// @brief Carrega o menu, mostrando as primeiras opções para o usuário
void menu(){
    // (Lógica aqui)
}