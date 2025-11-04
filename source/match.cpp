/*

Criado em: 25/09/2025 por Eduardo
Responsabilidade de: Eduardo
Finalizado em: --/--/2025

# Visão geral:
Arquivo .cpp complementar para implementar as funções, classes e
estruturas e utilizar as contantes e variáveis globais antes protótipadas no
header: "game.hpp"

# Uso:
Para ver os detalhes do uso das funções e métodos, leia a documentação em
formato Doxygen acima do cabeçalho da função

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include "../include/match.hpp"

// ================================< Funções >=================================

/// @brief Inicia um jogo para o usuário, e calcula a pontuação no fim
/// @return Pontuação ganha pelo jogador nesse jogo
int play() {
    int points = 0;

    Field::Generate();
    while (true) {
        // ^^^^ TODO: Tem que ser uma função para ver se todas as posições sem
        //      bombas foram reveladas ou não (continua enquanto não tiverem sido)
        Field::Display();

        std::string command;
        std::cout << "> ";
        std::cin >> command;

        if (command == "exit") break;
        if (command == "help") {
            Commands::List();

            std::cout << "->> pressione 'Enter' para voltar continuar o jogo." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string buff;
            std::getline(std::cin, buff);
            continue;
        }
        if (command == "clear") {
            Commands::ClearConsole();
            continue;
        }
        if (command == "dig") {
            cmm::index row, col;
            std::cin >> row >> col;

            if (!Commands::Dig(row, col)) break;
            continue;
        }
        if (command == "flag") {
            cmm::index row, col;
            std::cin >> row >> col;

            Commands::ToggleFlag(row, col);
            continue;
        }

        std::cout << "Comando invalido. Use o comando 'help' para ver os comandos existentes.\n";
    }

    Commands::ClearConsole();
    Field::RevealAll();
    Field::Display();

    std::cout << "Pontuacao ganha durante esse jogo: " << points << " Pontos.\n\n";
    std::cout << "->> pressione 'Enter' para voltar ao menu." << std::endl;

    // Ignora todo o input à esquerda que restou no buffer (ignora todos os
    // caracteres à esquerda até chegar na quebra de linha '\n'):
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string buff; // string temporária para armazenar a próx leitura
    std::getline(std::cin, buff); // Espera o usuário pressionar
    // Enter para finalizar o jogo

    return points;
}

// ===========================< Métodos de classes >===========================

// --------------------------------/ Commands /--------------------------------

/// @brief Imprime uma lista de comandos para o usuário e o que eles fazem
void Commands::List() {
    std::cout << "Comandos disponiveis:\n";
    std::cout << "dig [i] [j]: Cava a posição na linha [i] coluna [j].\n";
    std::cout << "flag [i] [j]:\n";
    std::cout << "- se tiver uma bandeira na linha [i] coluna [j]: Remove a bandeira;\n";
    std::cout << "- se não tiver uma bandeira na linha [i] coluna [j]: Adiciona uma bandeira.\n";
    std::cout << "clear: Limpa o texto do programa até então.\n";
    std::cout << "exit: Finaliza o jogo e fica com os pontos ganhos até aqui.\n";
    std::cout << std::endl;
}

/// @brief Cava uma certa posição expecíficada pelo usuário
/// @param row A linha do quadrado para ser cavado
/// @param col A coluna do quadrado para ser cavado
/// @return Retorna se a posição era segura para cavar [true] ou não [false]
/// @note Uma posição é segura para ser cavada se não houver uma bomba
///       naquela posição
/// @note Se for passada uma linha ou coluna inválida, imprime uma mensagem
///       para o usuário e retorna [true] <- já que ele não perdeu
bool Commands::Dig(cmm::index row, cmm::index col) {
    size_t height = GameConfig::Get("height");
    size_t width = GameConfig::Get("width");

    if (row <= 0 || row > height) {
        std::cout << "Linha invalida. Deve estar entre 1 e " << height << ".\n";
        return true;
    }
    if (col <= 0 || col > width) {
        std::cout << "Coluna invalida. Deve estar entre 1 e " << width << ".\n";
        return true;
    }

    FieldSquare &square = Field::At(--row, --col);

    if (square.BeingShown()) {
        std::cout << "Essa posicao ja esta cavada. Tente outra posição.\n";
        return true;
    }
    if (square.hasFlag()) {
        std::cout << "Não é possível cavar uma posicao com bandeira.\n";
        return true;
    }

    square.Reveal();
    return square.GetBombsNearby() != -1;
}

/// @brief Coloca uma bandeira em uma determinada posição, se antes não havia;
///        ou remove a bandeira em uma determinada posição, se já havia
/// @param row A linha da posição a ser marcada/desmarcada
/// @param col A coluna da posição a ser marcada/desmarcada
void Commands::ToggleFlag(cmm::index row, cmm::index col) {
    size_t height = GameConfig::Get("height");
    size_t width = GameConfig::Get("width");

    if (row <= 0 || row > height) {
        std::cout << "Linha invalida. Deve estar entre 1 e " << height << ".\n";
        return;
    }
    if (col <= 0 || col > width) {
        std::cout << "Coluna invalida. Deve estar entre 1 e " << width << ".\n";
        return;
    }
    FieldSquare &square = Field::At(--row, --col);

    if (square.BeingShown()) {
        std::cout << "Não eh possível marcar com bandeira uma posição já cavada.\n";
        return;
    }

    if (square.hasFlag()) square.RemoveFlag();
    else square.PlaceFlag();
}

/// @brief Limpa o console
void Commands::ClearConsole() {
#ifdef __WIN32__
    system("cls");
#else
    system("clear");
#endif
}