/*

# Visão geral:
Arquivo .cpp complementar para implementar as funções, constantes, classes e 
estruturas antes prototipadas no header "config.hpp"

# Uso:
Para ver os detalhes do uso das funções e métodos, passe o mouse por cima e
leia a documentação

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include "../include/config.hpp"

// ========================< Propriedades de classes >=========================

// ------------------------------/ GamesConfig /-------------------------------

// São inicializadas com valores mínimos
int GameConfig::Width = MIN_WIDTH_ND_HEIGHT;
int GameConfig::Height = MIN_WIDTH_ND_HEIGHT;
int GameConfig::TotalBombs = MIN_BOMBS_PER_AREA * (/* Area */ MIN_WIDTH_ND_HEIGHT * MIN_WIDTH_ND_HEIGHT);
int GameConfig::NoBombsRegion = MIN_NO_BOMBS_REGION;

// ===========================< Métodos de classes >===========================

// ------------------------------/ GamesConfig /-------------------------------

/// @brief Acessa uma propriedade expecifica da classe GameConfig
/// @param property Uma string passada por valor, cujo texto corresponde
///                 ao nome da propriedade a ser acessada
/// @return Retorna o valor inteiro da propriedade corespondente
/// @note O texto na string deve ser correspondente a uma propriedade válida, 
///       independentemente das letras minúsculas ou maiúsculas
/// @note Lança uma exceção para uma string inválida
int GameConfig::Get(std::string property){
    // Deixa a string toda maiúscula (assim não importa se os caracteres
    // estavam em maiúsculo ou minúsculo):
    std::transform(property.begin(), property.end(), property.begin(), ::toupper);

    if(property == "WIDTH"){
        return Width;
    }
    if(property == "HEIGHT"){
        return Height;
    }
    if(property == "TOTALBOMBS"){
        return TotalBombs;
    }
    if(property == "NOBOMBSREGION"){
        return NoBombsRegion;
    }
    
    throw("Argumento invalido passado para a funcao: int GameConfig::Get(std::string property). Eh necessario passar uma string correspondente a alguma propriedade existente na classe GameConfig.\n");
}

/// @brief Faz a leitura das configurações escolhidas pelo usuário, e armazena
///        elas na classe GameConfig
void GameConfig::InputSettings(){
// Primeira versão da configuração v.1.0

// TODO: generalizar partes do código (como por exemplo a validação),
// transformando-as em funções, se possível

    int width, height, totalBombs, noBombsRegion;
    char confirmation = 'N';
    
    // Entrada da altura e largura do campo minado:
    do{
        // Leitura inicial/principal:
        std::cout << "Digite a altura e largura do campo, respectivamente [min:" << MIN_WIDTH_ND_HEIGHT << ", max:" << MAX_WIDTH_ND_HEIGHT << "]:\n";
        
        std::cin >> width;
        std::cin >> height;

        // Validação da entrada:
        while((width < MIN_WIDTH_ND_HEIGHT || width > MAX_WIDTH_ND_HEIGHT) || (height < MIN_WIDTH_ND_HEIGHT || height > MAX_WIDTH_ND_HEIGHT)){
            std::cout << "Digite valores validos[min:" << MIN_WIDTH_ND_HEIGHT << ", max:" << MAX_WIDTH_ND_HEIGHT << "]:\n";

            std::cin >> width;
            std::cin >> height;
        }

        // Confirmação:
        std::cout << "Confirmar: |altura = " << height << "|, |largura = " << width << "| [S/N]?\n";
        std::cin >> confirmation;
    }while(confirmation != 'S');

    GameConfig::Width = width;
    GameConfig::Height = height;

    // ------------------------------------------------------------------------
    int area = width * height;

    int minBombs = MIN_BOMBS_PER_AREA * area;
    int maxBombs = MAX_BOMBS_PER_AREA * area;

    // Entrada do número de bombas:
    do{
        // Leitura inicial/principal:
        std::cout << "Digite o numero total de bombas[min:" << minBombs << ", max:" << maxBombs << "]:\n";
        
        std::cin >> totalBombs;

        // Validação da entrada:
        while(totalBombs < minBombs || totalBombs > maxBombs){
            std::cout << "Digite um valor valido[min:" << minBombs << ", max:" << maxBombs << "]:\n";

            std::cin >> totalBombs;
        }

        // Confirmação:
        std::cout << "Confirmar: |total de bombas = " << totalBombs << "| [S/N]?\n";
        std::cin >> confirmation;
    }while(confirmation != 'S');

    GameConfig::TotalBombs = totalBombs;

    int maxNoBombsRegion = MAX_NO_BOMBS_REGION_PER_TOTAL_AREA * area;

    // Entrada da região sem bombas inicial:
    do{
        // Leitura inicial/principal:
        std::cout << "Digite o numero de quadrados reservados para ficar sem bombas (regiao inicialmente revelada)[min:" << MIN_NO_BOMBS_REGION << ", min:" << maxNoBombsRegion << "]:\n";

        std::cin >> noBombsRegion;

        // Validação da entrada:
        while(noBombsRegion < MIN_NO_BOMBS_REGION || noBombsRegion > maxNoBombsRegion){
            std::cout << "Digite um valor valido[min:" << MIN_NO_BOMBS_REGION << ", max:" << maxNoBombsRegion << "]:\n";

            std::cin >> noBombsRegion;
        }

        // Confirmação:
        std::cout << "Confirmar: |Regiao sem bombas = " << noBombsRegion << "| [S/N]?\n";
        std::cin >> confirmation;
    }while(confirmation != 'S');

    GameConfig::NoBombsRegion = noBombsRegion;
}