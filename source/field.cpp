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
int FieldSquare::GetBombsNearby() { return this->BombsNearby; }

/// @brief Verifica se a posição atual está sendo exibida para o jogador
/// @return Se a posição está ou não sendo exibida para o jogador [true/false]
bool FieldSquare::BeingShown() { return this->Shown; }

/// @brief Verifica se a posição atual tem uma bandeira
/// @return Se a posição atual tem ou não uma bandeira [true/false]
bool FieldSquare::hasFlag() { return this->Flaged; }

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
    if (bombsNearby > 8 || bombsNearby < 0) throw std::runtime_error(errorMessage);

    this->BombsNearby = bombsNearby;
}

/// @brief Coloca uma bomba na posição atual
/// @note BombsNearby vai para -1
void FieldSquare::PlaceBomb() { this->BombsNearby = -1; }

/// @brief Coloca uma bandeira na posição atual
/// @note Não funciona se a posição atual tiver sido revelada (exceção)
void FieldSquare::PlaceFlag() {
    std::string errorMessage = "Não é possível colocar uma bandeira em uma";
    errorMessage += " posição revelada.";
    if (this->BeingShown()) throw std::runtime_error(errorMessage);

    this->Flaged = true;
}

/// @brief Remove a bandeira da posição atual
void FieldSquare::RemoveFlag() { this->Flaged = false; }

/// @brief Faz com que a posição atual passe a ser exibida para o jogador
void FieldSquare::Reveal() {
    std::string errorMessage = "Não é possível revelar uma posição na qual há";
    errorMessage += " uma bandeira. Retire-a caso queira revelar a posição.";
    if (this->Flaged) throw std::runtime_error(errorMessage);

    this->Shown = true;
}

/// @brief Verifica se o quadrado está sendo reservado
/// @return Se o quadrado está reservado [true/false]
bool FieldSquare::ReservedSquare() { return this->Reserved; }

/// @brief Reserva um quadrado para uma área
void FieldSquare::ReserveSquare() { this->Reserved = true; }

FieldSquare::FieldSquare() {
    // Construtor (Campo minado inicializa invisível e sem bombas)
    this->Shown = false;
    this->Flaged = false;
    this->BombsNearby = 0;
    this->Reserved = false;
}

// ---------------------------------/ Field /----------------------------------

/// @brief Acessa uma determinada posição do campo minado
/// @param row A linha dessa cédula
/// @param col A coluna dessa cédula
/// @return Uma referência à posição correspondente
/// @note Uma linha ou coluna inválida lança uma exceção
FieldSquare &Field::At(const cmm::index row, const cmm::index col) {
    return Field::Data.at(row).at(col); // Função .at() lança uma exceção para
    // índice inválido
}

void Field::ReserveNoBombRegion()
{
    //-------------- dados pegos do GameConfig -----------------
    int RegionNoBomb = GameConfig::Get("NOBOMBSREGION"); // Número de quadrados reservados
    int width = GameConfig::Get("WIDTH"); // Quantidade de colunas
    int height = GameConfig::Get("HEIGHT"); // Quantidade de linhas

    //------------- Atribuindo as variáveis os seus valores ----
    int side = sqrt(RegionNoBomb); // side: Lado da região quadrada

    //thick: borda, área que não será reservado
    int thick_width = (width - side) / 2;
    int thick_height = (height - side) / 2;


    //------------- Reservando quadrados ------------------------    
    for (int i = thick_height; i < thick_height + side; i++)
    {
        for (int j = thick_width; j < thick_width + side; j++)
        {
            Field::At(i, j).ReserveSquare();
            Field::At(i, j).Reveal();
        }
    }
}

/// @brief Gera o mapa do campo minado conforme as configurações do jogo
/// @note As configurações são baseadas na classe: GameConfig
void Field::Generate()
{ // Gera o mapa do campo minado

    //Variáveis pegas do GameConfig:
    int width = GameConfig::Get("WIDTH");
    int height = GameConfig::Get("HEIGHT");
    int bombs = GameConfig::Get("TOTALBOMBS");

    // Precenhendo a matriz
    auto row = std::vector<FieldSquare>(width, FieldSquare());
    Data = cmm::matrix<FieldSquare>(height, row);

    // Reservando a área:
    Field::ReserveNoBombRegion();

    //---------------------- Colocando bombas em lugares "aleatórios" --------------------------------

    std::mt19937 gen(std::time(nullptr));   // mt19937 é o gerador de números pseudo-aleatórios
    // A seed é o time

// Distribui uniformemente entre os números dejesados.
    std::uniform_int_distribution<int> dist_row(0, height - 1); //Números gerados para a linha;
    std::uniform_int_distribution<int> dist_col(0, width - 1);  //Números gerado para a coluna;

    while (bombs > 0)
    {
        int RowRandow = dist_row(gen);  // Índice pseudo-aleatório na linha;
        int ColRandow = dist_col(gen);  // Índice pseudo-aleatório na coluna; 


        if (At(RowRandow, ColRandow).GetBombsNearby() != -1 && !At(RowRandow, ColRandow).ReservedSquare())
        {
            At(RowRandow, ColRandow).PlaceBomb();

            bombs--;
        }
    }


    // ------------------ Colocando o número de bombas próximas dos quadrados nos quadrados --------------------    
    int bombsNear = 0;

    //---- *Descobri como melhorar essa parte, para ficar menos confuso. ----
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (At(row, col).GetBombsNearby() != -1) // Confere cada cédula do campo se não é bomba;
            {
                for (int k = row - 1; k <= row + 1; k++)
                {
                    for (int l = col - 1; l <= col + 1; l++) // Vai indo nos quadrados adjacentes
                    {
                        if (k < 0 || k > height - 1 || l < 0 || l > width - 1)
                            continue; // Se o quadrado se encontra fora do campo, ignora;

                        if (At(k, l).GetBombsNearby() == -1)
                        {
                            bombsNear++;

                            At(row, col).SetBombsNearby(bombsNear);
                            // Verifica se os quadrados adjacentes são uma bomba
                            // e informa à cédula quantas bombas há ao redor; 
                        }
                    }
                }
            }

            bombsNear = 0;
        }
    }
}

void Field::RevealAll()
{
    for (auto &row : Data)
    {
        for (auto &square : row)
        {
            square.Reveal();
        }
    }
}

/// @brief Checa se todas as posições sem bomba do campo minado foram reveladas
/// @return Retorna [true] se tiverem sido reveladas, [false] caso contrário
/// @note Se o retorno for verdadeiro [true], quer dizer que o jogador ganhou
bool Field::IsRevealed()
{
    // implementação
}

/// @brief Exibe o campo minado para o jogador
/// @todo Colocar uma numeração nas linhas e colunas, e se quiser POSTERIORMENTE,
///       pode colocar letras ao invés de números em alguma das duas.
void Field::Display()
{
    for (auto row : Data)
    {
        for (auto square : row) // Vai indo de cúcula em cécula do campo;
        {
            if (square.hasFlag()) // Verifica se tem uma bandeira;
                std::cout << "P  ";

            else
            {
                if (!square.BeingShown()) // Verifica se não está sendo mostrado;
                    std::cout << "~  ";
                else
                {
                    if (square.GetBombsNearby() == -1) // Verifica se é uma bomba;
                        std::cout << "X  ";
                    else
                        std::cout << square.GetBombsNearby() << "  ";
                }
            }
        }

        std::cout << "\n";
    }
}
