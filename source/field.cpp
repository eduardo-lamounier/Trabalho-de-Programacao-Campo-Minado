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

// ========================< Propriedades de classes >=========================

// ---------------------------------/ Field /----------------------------------

cmm::matrix<FieldSquare> Field::Data = {};

// ===========================< Métodos de classes >===========================

// ------------------------------/ Field Square /------------------------------

/// @brief Acessa a quantidade de bombas ao redor da posição atual do campo
///        minado
/// @note Retorna -1 se há uma bomba NA posição atual
/// @return A quantidade de bombas ao redor da posição atual
int FieldSquare::GetBombsNearby(){
    return this->BombsNearby;
}

/// @brief Verifica se a posição atual está sendo exibida para o jogador
/// @return Se a posição está ou não sendo exibida para o jogador [true/false]
bool FieldSquare::BeingShown() {
    return this->Shown;
}

/// @brief Verifica se a posição atual tem uma bandeira
/// @return Se a posição atual tem ou não uma bandeira [true/false]
bool FieldSquare::isFlaged() {
    return this->Flaged;
}

/// @brief Atualiza a quantidade de bombas ao redor da posição atual (e checa
///        por um parâmetro inválido)
/// @param bombsNearby O valor que vai ser atribuído à quantidade de bombas
///                    ao redor da posição atual
/// @note Não é possível existir mais de 8 bombas ao redor, nem menos de 0
/// @note Por mais que -1 represente a presença de uma bomba na posição, a
///       função que deve ser utilizada para colocar a bomba é:
///       'void FieldSquare::PlaceBomb()'.
void FieldSquare::SetBombsNearby(const int bombsNearby) {
    std::string errorMessage = "Valor invalido passado para o metodo: ";
    errorMessage += "void FieldSquare::SetBombsNearb(const int bombsNearby).";
    if(bombsNearby > 8 || bombsNearby < 0) throw std::runtime_error(errorMessage);

    this->BombsNearby = bombsNearby;
}

/// @brief Coloca uma bomba na posição atual
/// @note BombsNearby vai para -1
void FieldSquare::PlaceBomb() {
    this->BombsNearby = -1;
}

/// @brief Coloca uma bandeira na posição atual
/// @note Não funciona se a posição atual tiver sido revelada (exceção)
void FieldSquare::PlaceFlag() {
    std::string errorMessage = "Não é possível colocar uma bandeira em uma";
    errorMessage += " posição revelada.";
    if(this->BeingShown()) throw std::runtime_error(errorMessage);

    this->Flaged = true;
}

/// @brief Remove a bandeira da posição atual
void FieldSquare::RemoveFlag() {
    this->Flaged = false;
}

/// @brief Faz com que a posição atual passe a ser exibida para o jogador
/// @return Retorna se a posição revelada tinha ou não uma bomba
/// @note i.e. retorna 'true' se o jogador tiver perdido ao tentar revelar esta
///       posição, ou 'false' caso contrário
bool FieldSquare::Reveal() {
    std::string errorMessage = "Não é possível revelar uma posição na qual há";
    errorMessage += " uma bandeira. Retire-a caso queira revelar a posição.";
    if(this->Flaged) throw std::runtime_error(errorMessage);

    this->Shown = true;
    return this->BombsNearby == -1; // Há uma bomba?
}

FieldSquare::FieldSquare() {
    // Construtor (Campo minado inicializa invisível e sem bombas)
    this->Shown = false;
    this->Flaged = false;
    this->BombsNearby = 0;
}

// ---------------------------------/ Field /----------------------------------

/// @brief Acessa uma determinada posição do campo minado
/// @param row A linha dessa cédula
/// @param col A coluna dessa cédula
/// @return Uma referência à posição correspondente
/// @note Uma linha ou coluna inválida lança uma exceção
FieldSquare& Field::At(const cmm::index row, const cmm::index col) {
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
// Exibição do campo minado - v1

    for(auto& row : Field::Data) {
        for(auto pos : row) {
            // Para cada cédula do campo minado:
            if(pos.BeingShown()) {
                std::cout << pos.GetBombsNearby() << " ";
            } else if(pos.isFlaged()) {
                std::cout << "f ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
