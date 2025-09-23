/* 

Criado em: 27/08/2025 por Eduardo
Responsabilidade de: Miguel
Finalizado em: --/--/2025

Arquivo que ao ser compilado, vai dar origem ao executável do jogo, além de
ser o arquivo de implmentação do menu

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include "../include/config.hpp"

void menu(char jogar_config_sair)

int main(){ 

;// auto config, auto sair)

printf("\n\nCampo Minado\n\nJogo feito por Eduardo Lamounier, Heitor Freitas e Miguel Peterson\n.");

printf("Digite:\n1.Jogar\n2.Configuracões\n3.Sair");
scanf("%", &jogar_config_sair);

switch (jogar_config_sair)
{

    case '1':
    /* code */
        break;
    case '2':
        break;
    case '3':
        printf("nao vou jogar campo minado nao, o silksong me espera");
        return 0;
        break;

default:
    break;
    printf("1, 2 ou 3");
}
}



// ==================================< main >==================================

int main(int argc, char *argv[]) {
    // (Talvez pegar dados do usuário como nickname e afins para colocar em
    // uma classe - apenas uma ideia)
    // menu(); // Cria o menu e pede pelas primeiras entradas do usuário

    return 0;
}