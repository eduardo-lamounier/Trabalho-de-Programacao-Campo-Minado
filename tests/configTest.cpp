/*

Criado por Eduardo
Data de criação: 28/08/2025
Finalizado em: --/--/2025

Arquivo de teste para o header config.hpp, tem como objetivo testar as funções 
e métodos (que são implementados em config.cpp)

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// Inclusão do header config.cpp:
#include "../include/config.hpp"

void printConfigs(); // Imprime as configurações de GameConfig

// ==================================< Main >==================================

int main(int argc, char *argv[]){
    // Verificação da função Get() e dos valores inicialmente atribuídos às 
    // propriedades de GameConfig:
    printConfigs();
    
    // Testa a função de configuração:
    GameConfig::InputSettings();

    // Imprime as configurações depois da configuração feita pelo usuário
    printConfigs();

    return 0;
}

/// @brief Imprime todas as propriedades de GameConfig
void printConfigs(){
    using namespace std;
    
    cout << "GameConfig::Width = " << GameConfig::Get("Width") << '\n';
    cout << "GameConfig::Height = " << GameConfig::Get("Height") << '\n';
    cout << "GameConfig::TotalBombs = " << GameConfig::Get("TotalBombs") << '\n';
    cout << "GameConfig::NoBombsRegion = " << GameConfig::Get("NoBombsRegion") << '\n';
}