/*

Criado por Eduardo
Data de criação: 28/08/2025

Arquivo de teste para o header config.hpp, tem como objetivo testar as funções 
e classes adicionadas

*/

#include<iostream>

// Inclusão do header config.cpp:
#include "../include/config.hpp"

using namespace std;

int main(int argc, char *argv[]){
    // Verificação da função Get() e dos valores inicialmente atribuídos às 
    // propriedades de GameConfig:
    cout << "GameConfig::Width = " << GameConfig::Get("Width") << endl;
    cout << "GameConfig::Height = " << GameConfig::Get("Height") << endl;
    cout << "GameConfig::TotalBombs = " << GameConfig::Get("TotalBombs") << endl;
    cout << "GameConfig::NoBombsRegion = " << GameConfig::Get("NoBombsRegion") << endl;

    

    return 0;
}