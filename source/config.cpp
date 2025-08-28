/*

Arquivo .cpp complementar para implementar as funções, constantes, classes e 
estruturas antes prototipadas no header "config.hpp"

*/

#include<string>

#include "config.hpp"

// ======================< Métodos da classe GameConfig >======================

/// @brief Acessa uma propriedade expecifica da classe GameConfig
/// @param property Uma referência ao início de uma string, cujo texto 
///                 corresponde ao nome da propriedade
/// @return Retorna o valor inteiro da propriedade corespondente
/// @note Lança uma exceção para uma string inválida
int GameConfig::get(char *property){
    if(strcmp(property, "width") == 0){
        return width;
    }else if(strcmp(property, "height") == 0){
        return height;
    }else if(strcmp(property, "totalBombs") == 0){
        return totalBombs;
    }else if(strcmp(property, "noBombsRegion") == 0){
        return noBombsRegion;
    }else{
        throw ("Argumento inválido passado para a função: int GameConfig::get(char *property)\n Digite uma string correspondente a alguma propriedade válida da classe GameConfig\n");
    }
}

void GameConfig::inputSettings(){
    // (Lógica aqui)
}

// ================================< Menu >====================================

void menu(){
    // (Lógica aqui)
}