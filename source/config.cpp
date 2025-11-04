/*

Criado em: 27/08/2025 por Eduardo
Responsabilidade de: Miguel
Finalizado em: 25/09/2025

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

    if (property == "WIDTH") {
        return GameConfig::Width;
    }
    if (property == "HEIGHT") {
        return GameConfig::Height;
    }
    if (property == "TOTALBOMBS") {
        return GameConfig::TotalBombs;
    }
    if (property == "NOBOMBSREGION") {
        return GameConfig::NoBombsRegion;
    }

    std::string errorMessage = "Argumento invalido passado para a funcao: ";
    errorMessage += "int GameConfig::Get(std::string property). ";
    errorMessage += "Eh necessario passar uma string correspondente a alguma ";
    errorMessage += "propriedade existente na classe GameConfig.\n";
    throw std::runtime_error(errorMessage);
}

/// @brief Faz a leitura das configurações escolhidas pelo usuário, e armazena
///        elas na classe GameConfig
void GameConfig::InputSettings() {
    // Segunda versão da configuração - v.2

    // ------------------------------------------------------------------------
        /// @brief Valida a leitura das configurações
        /// @param configs Um conjunto de referências às variáveis que vão
        ///                armazenar as configurações antes da confirmação pelo
        ///                usuário
        /// @param min O valor mínimo que essas configurações podem assumir
        /// @param max O valor máximo que essas configurações podem assumir
    constexpr auto validation = [] (std::vector<int *> configs, const int min,
        const int max) {

            /// @brief Verifica se as configurações são válidas depois de repetir
            ///        o input
            /// @return Retorna se todas as configurações são válidas ou não
            const auto validate = [&configs, min, max] () {
                // Checa se alguma das configurações são inválidas:
                for (auto config : configs) {
                    if (*config < min || *config > max) return false;
                }

                // Se chegou até aqui, todas as configurações são válidas
                return true;
                };

            while (!validate()) {
                std::cout << "Digite valores validos";
                std::cout << "[min: " << min << ", max:" << max << "]:\n";

                std::cout << "> " << std::flush;
                for (auto config : configs) std::cin >> *config;
            }
        };
    // ------------------------------------------------------------------------
        /// @brief Faz o input de um certo conjunto de configurações com as
        ///        mesmas restrições enquanto pede para o usuário confirmá-las
        /// @param inputText Texto do input dessas configurações
        /// @param configs Um vetor de referências para as variáveis que vão
        ///                armazenar essas configurações
        /// @param configNames Um vetor com os nomes das configuraões, na mesma
        ///                    ordem que 'configTest'
        /// @param min O valor mínimo que essas configurações podem assumir
        /// @param max O valor máximo que essas configurações podem assumir
    auto input = [&validation](const std::string inputText,
        std::vector<int *> configs,
        const std::vector<std::string> configNames,
        const int min, const int max) {

            std::string errorMessage = "Valores inválidos passados para a função:";
            errorMessage = "lambda input em: void GameConfig::InputSettings()";
            if (configs.size() != configNames.size()) throw std::runtime_error(errorMessage);

            char confirmation = 'N';

            /// @brief Pede para o usuário confirmar ou não as configurações
            ///        inseridas e atualiza 'confirmed'
            const auto confirm = [&validation, &confirmation, &configs, &configNames] () {
                std::cout << "Confirmar[S/N]?\n";

                for (cmm::index i = 0; i < configs.size(); i++) {
                    // Imprime o valor cada configuração inserida:
                    std::cout << "|" << configNames[i] << " = ";
                    std::cout << *configs[i] << "|\n";
                }

                std::cout << "> " << std::flush;
                std::cin >> confirmation;
                };

            while (confirmation != 'S') {
                std::cout << inputText;
                std::cout << "[min: " << min << ", max: " << max << "]:\n";

                std::cout << "> " << std::flush;
                // Faz a leitura de cada configuração:
                for (auto config : configs) std::cin >> *config;

                // Validação da entrada:
                validation(configs, min, max);

                // Confirmação das configurações inseridas:
                confirm();
            }

        };
    // ----------------------------------------------------------------------------

    int width, height, totalBombs, noBombsRegion;
    std::string message; // Mensagem de input (atualiza para cada configuração)

    // Entrada da altura e largura do campo minado:
    message = "Digite a altura e largura do campo, respectivamente";

    input(message, { &height, &width }, { "altura", "largura" },
        MIN_WIDTH_ND_HEIGHT, MAX_WIDTH_ND_HEIGHT);

    // ------------------------------------------------------------------------
    const int area = width * height;

    const int minBombs = MIN_BOMBS_PER_AREA * area;
    const int maxBombs = MAX_BOMBS_PER_AREA * area;

    // Entrada do número de bombas:
    message = "Digite o numero total de bombas";

    input(message, { &totalBombs }, { "total de bombas" }, minBombs, maxBombs);

    // ------------------------------------------------------------------------
    const int maxNoBombsRegion = MAX_NO_BOMBS_REGION_PER_TOTAL_AREA * area;

    // Entrada da região sem bombas inicialmente:
    message = "Digite o numero de quadrados reservados para ficarem";
    message += " sem bombas (regiao inicialmente revelada)";

    input(message, { &noBombsRegion }, { "regiao sem bombas" },
        MIN_NO_BOMBS_REGION, maxNoBombsRegion);

    // ------------------------------------------------------------------------

    // Atribuição final:
    GameConfig::Width = width;
    GameConfig::Height = height;
    GameConfig::TotalBombs = totalBombs;
    GameConfig::NoBombsRegion = noBombsRegion;
}