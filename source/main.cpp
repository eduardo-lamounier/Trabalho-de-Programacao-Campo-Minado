/* 

Criado em: 27/08/2025 por Eduardo
Responsabilidade de: Miguel
Finalizado em: --/--/2025

Arquivo que ao ser compilado, vai dar origem ao executável do jogo, além de
ser o arquivo de implmentação do menu

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include "../include/config.hpp"

void menu(); // Protótipo da função dedicada à implementação do menu

// ==================================< main >==================================

int main(int argc, char *argv[]) {
    // (Talvez pegar dados do usuário como nickname e afins para colocar em
    // uma classe - apenas uma ideia)
    // menu(); // Cria o menu e pede pelas primeiras entradas do usuário

    return 0;
}

// ==================================< menu >==================================

void menu() {
    int jogar_config_sair;
    bool entradaValida;

    std::cout << "\n\nCampo Minado\n\nJogo feito por Eduardo, Heitor e Miguel\n.";

    std::cout << "Digite:\n1.Jogar\n2.Configuracões\n3.Sair";
    std::cin >> jogar_config_sair;

    while(!entradaValida) {
        entradaValida = jogar_config_sair >= 1 && jogar_config_sair <= 3;
        switch (jogar_config_sair) {
            case '1':
                // Jogar
                break;
            case '2':
                // Configurar
                break;
            case '3':
                // Sair
                std::cout << "\n<Programa finalizado, obrigado por jogar!\n";
                break;
            default:
                // Usuário é um imbecil
                break;
                std::cout << "Digite uma opção válida: [1-3]\n";
        }
    }
}
