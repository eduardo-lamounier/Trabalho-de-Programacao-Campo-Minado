# Compilador e flags:
CC = g++
FLAGS = -Wall -Iinclude

# Nomes dos executáveis:
APLICACAO = bin/app.exe
TESTE_CONFIG = bin/configTest.exe

# Fontes para cada executável:
APP_SOURCES = $(wildcard source/*.cpp) # Todos os arquivos .cpp em source
TEST_CONFIG_SOURCES = testing/configTest.cpp source/config.cpp

# Target padrão: Compila tudo:
all: app config-test

# Linka e produz as aplicações:
app: $(APP_SOURCES)
	@echo ...Linkando e produzindo a aplicacao final
	@$(CC) $(FLAGS) $(APP_SOURCES) -o $(APLICACAO)

config-test: $(TEST_CONFIG_SOURCES)
	@echo ...Linkando e produzindo a aplicacao teste para config.hpp
	@$(CC) $(FLAG) $(TEST_CONFIG_SOURCES) -o $(TESTE_CONFIG)

# Roda a aplicação final:
run-app: app
	@echo ...Rodando a aplicacao final
	@echo ================================================================================
	@$(APLICACAO)
	@echo ================================================================================

# Roda os testes específicos:
run-config-test: config-test
	@echo ...Executando a aplicacao teste para config.hpp
	@echo ================================================================================
	@$(TESTE_CONFIG)
	@echo ================================================================================

