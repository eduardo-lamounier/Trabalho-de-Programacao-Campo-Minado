/*

Criado em: 24/09/2025 por Eduardo
Responsabilidade de: Heitor
Finalizado em: --/--/2025

# Visão geral:
Arquivo .cpp complementar para implementar as funções, classes e 
estruturas e utilizar as contantes e variáveis globais antes protótipadas no
header: "generation.hpp"

# Uso:
Para ver os detalhes do uso das funções e métodos, leia a documentação em
formato Doxygen acima do cabeçalho da função

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include "../include/field.hpp"

// ===========================< Métodos de classes >===========================

// ------------------------------/ Field Square /------------------------------

/// @brief Acessa a quantidade de bombas ao redor da posição atual do campo
///        minado
/// @return O valor inteiro correspondente
int FieldSquare::GetBombsNearby(){
    return this->BombsNearby;
}

/// @brief Verifica se a posição atual está sendo exibida para o jogador
/// @return O valor booleano correspondente
bool FieldSquare::BeingShown() {
    return this->Shown;
}

/// @brief Atualiza a quantidade de bombas ao redor da posição atual (e checa
///        por um parâmetro inválido)
/// @param bombsNearby O valor que vai ser atribuído à quantidade de bombas
///                    ao redor da posição atual
/// @note Para um parâmetro inválido, essa função lança uma exceção
/// @note Por mais que -1 represente a presença de uma bomba na posição, a
///       função que deve ser utilizada para colocar a bomba é:
///       void FieldSquare::PlaceBomb(). Por isso, bombsNearby sendo -1 conta
///       como valor inválido
void FieldSquare::SetBombsNearby(const int bombsNearby) {
    std::string errorMessage = "Valor invalido passado para o metodo: ";
    errorMessage += "void FieldSquare::SetBombsNearb(const int bombsNearby).\n";
    if(bombsNearby > 8 || bombsNearby < 0) throw(errorMessage);

    this->BombsNearby = bombsNearby;
}

/// @brief Coloca uma bomba na posição atual
/// @note BombsNearby vai para -1
void FieldSquare::PlaceBomb() {
    this->BombsNearby = -1;
}

/// @brief Faz com que a posição atual passe a ser exibida para o jogador
void FieldSquare::See() {
    this->Shown = true;
}

FieldSquare::FieldSquare() {
    // Construtor (Campo minado inicializa invisível e sem bombas)
    this->Shown = false;
    this->BombsNearby = 0;
}

// ---------------------------------/ Field /----------------------------------

/// @brief Acessa uma determinada posição do campo minado
/// @param row A linha dessa cédula
/// @param col A coluna dessa cédula
/// @return Uma referência à posição correspondente
/// @note Uma linha ou coluna inválida lança uma exceção
FieldSquare& Field::At(const index row, const index col) {
    return Field::Data.at(row).at(col); // Função .at() lança uma exceção para
                                         // índice inválido
}

/// @brief Gera o mapa do campo minado conforme as configurações do jogo
/// @note As configurações são baseadas na classe: GameConfig
void Field::Generate() {
    // Gera o mapa do campo minado
}

/// @brief Exibe o campo minado para o jogador
void Field::Display() {
    // Imprime o campo minado
}
