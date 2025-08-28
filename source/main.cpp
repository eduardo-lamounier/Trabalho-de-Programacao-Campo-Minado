/* 
Arquivo que ao ser compilado, vai dar origem ao executável do jogo
*/

#include<iostream>
#include "config.hpp"

using namespace std;

// ==================================< main >==================================

int main(int argc, char *argv[]){
    // (Talvez pegar dados do usuário como nickname e afins para colocar em
    // uma classe - apenas uma ideia)
    menu(); // Cria o menu e pede pelas primeiras entradas do usuário
    // (Chama a função para o usuário escolher as configurações do jogo)

    return 0;
}