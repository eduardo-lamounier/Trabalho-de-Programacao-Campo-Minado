/*

Criado em: 27/08/2025 por Eduardo
Responsabilidade de: Miguel
Finalizado em: --/--/2025

# Visão geral:
Arquivo .cpp complementar para implementar as funções, classes e 
estruturas e utilizar as contantes e variáveis globais antes protótipadas no
header: "config.hpp"

# Uso:
Para ver os detalhes do uso das funções e métodos, leia a documentação em
formato Doxygen acima do cabeçalho da função

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
int GameConfig::Get(std::string property) {
    // Deixa a string toda maiúscula (assim não importa se os caracteres
    // estavam em maiúsculo ou minúsculo):
    std::transform(property.begin(), property.end(), property.begin(), ::toupper);

    if(property == "WIDTH") {
        return GameConfig::Width;
    }
    if(property == "HEIGHT") {
        return GameConfig::Height;
    }
    if(property == "TOTALBOMBS") {
        return GameConfig::TotalBombs;
    }
    if(property == "NOBOMBSREGION") {
        return GameConfig::TotalBombs;
    }
    
    throw("Argumento invalido passado para a funcao: int GameConfig::Get(std::string property). Eh necessario passar uma string correspondente a alguma propriedade existente na classe GameConfig.\n");
}

/// @brief Faz a leitura das configurações escolhidas pelo usuário, e armazena
///        elas na classe GameConfig
void GameConfig::InputSettings() {
// Segunda versão da configuração v.2
    
// TODO: Generalizar a operação de entrada dos valores e sua confirmação,
// assim como foi feito com a operação de validação

// TOFIX: A região sem bombas está sempre sendo igual à quantidade total de bombas

// ------------------------------------------------------------------------
    /// @brief Valida a leitura das configurações
    /// @param configs Um conjunto de referências às variáveis que vão
    ///                armazenar as configurações antes da confirmação pelo
    ///                usuário
    /// @param min O valor mínimo que essas configurações podem assumir
    /// @param max O valor máximo que essas configurações podem assumir
    const auto validation = [] (std::vector<int*> configs, const int min,
                                const int max) {
        bool valid;

        /// @brief Verifica se as configurações são válidas depois de repetir
        ///        o input, atualizando 'valid'
        const auto updateValidation = [&valid, &configs, min, max] () {
            valid = true;

            for(auto config : configs){
                valid = valid && *config >= min && *config <= max;
            }
        };

        updateValidation();
        while(!valid){
            std::cout << "Digite valores validos";
            std::cout << "[min: " << min << ", max:" << max << "]:\n";
            
            for(auto config : configs) std::cin >> *config;

            updateValidation();
        }
    };
// ------------------------------------------------------------------------

    int width, height, totalBombs, noBombsRegion;
    char confirmation = 'N';
    
    // Entrada da altura e largura do campo minado:
    do {
        // Leitura inicial/principal:
        std::cout << "Digite a altura e largura do campo, respectivamente";
        std::cout << "[min:" << MIN_WIDTH_ND_HEIGHT;
        std::cout << ", max:" << MAX_WIDTH_ND_HEIGHT << "]:\n";
        
        std::cin >> width;
        std::cin >> height;

        // Validação da entrada:
        validation({&height, &width}, MIN_WIDTH_ND_HEIGHT, MAX_WIDTH_ND_HEIGHT);

        // Confirmação:
        std::cout << "Confirmar: ";
        std::cout << "|altura = " << height << "|, ";
        std::cout << "|largura = " << width << "| [S/N]?\n";

        std::cin >> confirmation;
    }while(confirmation != 'S');

    GameConfig::Width = width;
    GameConfig::Height = height;

    // ------------------------------------------------------------------------
    const int area = width * height;

    const int minBombs = MIN_BOMBS_PER_AREA * area;
    const int maxBombs = MAX_BOMBS_PER_AREA * area;

    // Entrada do número de bombas:
    do {
        // Leitura inicial/principal:
        std::cout << "Digite o numero total de bombas";
        std::cout << "[min:" << minBombs << ", max:" << maxBombs << "]:\n";
        
        std::cin >> totalBombs;

        // Validação da entrada:
        validation({&totalBombs}, minBombs, maxBombs);

        // Confirmação:
        std::cout << "Confirmar: ";
        std::cout << "|total de bombas = " << totalBombs << "| [S/N]?\n";
        std::cin >> confirmation;
    }while(confirmation != 'S');

    GameConfig::TotalBombs = totalBombs;

    const int maxNoBombsRegion = MAX_NO_BOMBS_REGION_PER_TOTAL_AREA * area;

    // Entrada da região sem bombas inicial:
    do {
        // Leitura inicial/principal:
        std::cout << "Digite o numero de quadrados reservados para ficar sem bombas";
        std::cout << " (regiao inicialmente revelada)";
        std::cout << "[min:" << MIN_NO_BOMBS_REGION << ", min:" << maxNoBombsRegion << "]:\n";

        std::cin >> noBombsRegion;

        // Validação da entrada:
        validation({&noBombsRegion}, MIN_NO_BOMBS_REGION, maxNoBombsRegion);

        // Confirmação:
        std::cout << "Confirmar: |regiao sem bombas = " << noBombsRegion << "| [S/N]?\n";
        std::cin >> confirmation;
    }while(confirmation != 'S');

    GameConfig::NoBombsRegion = noBombsRegion;
}