/*

Criado por Eduardo
Data de criação: 25/09/2025
Finalizado em: --/--/2025

Arquivo de teste para o header field.hpp, tem como objetivo testar as funções 
e métodos (que são implementados em config.cpp)

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

// Inclusão do header field.hpp:
#include "../include/field.hpp"

void testFieldSquare();
void testField();

// ==================================< Main >==================================

int main(int argc, char *argv[]){
    int opcao;
    std::cout << "Selecione uma das seguintes opcoes:\n";
    std::cout << "1. Testar FieldSquare individualmente\n";
    std::cout << "2. Testar Field\n" << std::endl;

    std::cin >> opcao;
    if(opcao == 1) {
        testFieldSquare();
    } else if(opcao == 2) {
        // testField();
    } else {
        std::cout << "Entrada invalida." << std::endl;
    }

    return 0;
}

// ============================< Funções de teste >============================

// --------------------------/ Teste de FieldSquare /--------------------------

void testFieldSquare() {
    FieldSquare cedula;

    const auto print = [&cedula] () {
        std::cout << "BombsNearby: " << cedula.GetBombsNearby() << "\n";
        std::cout << "Flaged: " << cedula.isFlaged() << "\n";
        std::cout << "Shown: " << cedula.BeingShown() << std::endl;
    };

    print();

    char placeBombs;
    std::cout << "Deseja colocar uma bomba na posicao atual[S/N]? " << std::flush;
    std::cin >> placeBombs;
    if(placeBombs == 'S') cedula.PlaceBomb();
    else {
        int bombsNearby;
        std::cout << "Digite quantas bombas ha ao redor da posicao atual: " << std::flush;
        std::cin >> bombsNearby;
        cedula.SetBombsNearby(bombsNearby);
    }

    char reveal;
    std::cout << "Revelar a posicao atual[S/N]? " << std::flush;
    std::cin >> reveal;
    if(reveal == 'S') cedula.Reveal();

    char flag;
    std::cout << "Colocar uma bandeira na posição atual[S/N]? " << std::flush;
    std::cin >> flag;
    if(flag == 'S') cedula.PlaceFlag();

    print();
}

// -----------------------------/ Teste de Field /-----------------------------

void testField() {
    // Teste do campo minado
}