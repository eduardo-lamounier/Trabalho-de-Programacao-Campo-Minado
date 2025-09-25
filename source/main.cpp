/* 

Criado em: 27/08/2025 por Eduardo
Responsabilidade de: Miguel
Finalizado em: 25/09/2025

Arquivo que ao ser compilado, vai dar origem ao executável do jogo, além de
ser o arquivo de implmentação do menu

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include "../include/config.hpp"
#include "../include/game.hpp"

bool menu(int& points); // Protótipo da função dedicada à implementação do menu

// ==================================< main >==================================

int main(int argc, char *argv[]) {
    int totalPoints = 0;
    // TODO - só se sobrar tempo no planejamento:
    // - Salvar as pontuações de cada usuário em um arquivo e implementar login
    // e cadastro;
    // - Fazer um top melhores jogadores (mas provavelmente não seria muito
    // interessante porque só salvaria de maneira local)

    while(!menu(totalPoints)); // Pede pelas primeiras entradas do usuário
                               // enquanto ele não desejar finalizar o programa

    std::cout << "Pontuacao total ganha durante tempo de execucao:\n";
    std::cout << totalPoints << " Pontos.";
    std::cout << "\n\nMuito obrigado por jogar!!" << std::endl;

    return 0;
}

// ==================================< menu >==================================

/// @brief Pede pela seleção do usuário para alguma opção do menu
/// @param points Referência à pontuação atual do jogador, na qual as
///               pontuações ganhas nos jogos vão ser somadas
/// @return Se o programa deve finalizar ou não
bool menu(int& points) {
    char opcao;

    std::cout << "\nBem-vindo ao Campo Minado\nJogo feito por: Eduardo, Heitor e Miguel\n\n";
    std::cout << "Por favor, selecione uma das seguintes opções:\n";
    std::cout << "1.Jogar\n2.Configuracoes\n3.Sair\n\n";

    while(true) {
        std::cout << "> " << std::endl;
        std::cin >> opcao;

        switch (opcao) {
            case '1':
                // Jogar:
                points += play();
                return false; // Usuário não pretende finalizar o programa
            case '2':
                // Configurar:
                GameConfig::InputSettings();
                return false; // Usuário não pretende finalizar o programa
            case '3':
                // Sair:
                return true; // Usuário pretende finalizar o programa
            default:
                // Usuário é um imbecil (input inválido):
                std::cout << "Digite uma opção válida: [1-3]\n";
                break;
        }
    }
}
