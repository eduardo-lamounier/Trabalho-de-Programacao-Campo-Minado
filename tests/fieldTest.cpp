/*

Criado por Eduardo
Data de criação: 25/09/2025
Finalizado em: 08/11/2025

Arquivo de teste para o header field.hpp, tem como objetivo testar as funções
e métodos (que são implementados em config.cpp)

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// Inclusão do header field.hpp:
#include "../include/field.hpp"


// ==================================< Main >==================================

int main(int argc, char *argv[])
{

    GameConfig::InputSettings();
    Field::Generate();
    Field::Display();
    std::cout << "\n" << Field::IsRevealed();
    std::cout << "\n" << Field::SquaresRevealed();

    Field::RevealAll();
    std::cout << "\n";
    Field::Display();
    std::cout << "\n" << Field::IsRevealed();
    std::cout << "\n" << Field::SquaresRevealed();
    std::cout << std::endl;

    return 0;
}

// ============================< Funções de teste >============================
