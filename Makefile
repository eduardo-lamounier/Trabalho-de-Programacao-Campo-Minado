# 
# Criado em: 29/08/2025 por Eduardo
# Responsabilidade de: Eduardo
# Finalizado em: --/--/2025
#
# # Visão geral:
# Programa usado para facilitar a compilação dos executáveis do projeto, assim
# como serve para organizar a execução de diferentes executáveis (em /bin)
#
# # Uso:
# 	* Use o comando 'make app' para compilar a aplicação principal
# 	* Use o comando 'make all' para compilar todos os arquivos fontes (na pasta
# /source)
# 	* Use o comando 'make featname-test' para compilar o programa que testa a
# feature 'featname' (é o nome de algum header da pasta /include)
# 	* Use o comando 'make run-app' para rodar a aplicação 
# 	* Use o comando 'make run-featname-test' (onde 'featname' é o nome da
# feature, algum header da pasta /include) para rodar o programa de teste
# 
# <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

# Compilador e flags:
CC = g++
FLAGS = -Wall -Iinclude # Sujeito a adições

# Nomes dos executáveis:
APLICACAO = bin/campo-minado.exe
TESTE_CONFIG = bin/configTest.exe
TESTE_CAMPO = bin/fieldTest.exe

# Fontes para cada executável:
APP_SOURCES = $(wildcard source/*.cpp) # Todos os arquivos .cpp em source
TEST_CONFIG_SOURCES = tests/configTest.cpp source/config.cpp
TEST_CAMPO_SOURCES = tests/fieldTest.cpp source/field.cpp source/config.cpp

ifeq ($(OS),Windows_NT)
    MKDIR = @if not exist $(1) mkdir $(1)
else
    MKDIR = @mkdir -p $(1)
endif

create-bin:
	$(call MKDIR,bin)

# Linka e produz as aplicações:
app: $(APP_SOURCES) create-bin
	@echo ...Linkando e produzindo a aplicacao final
	@$(CC) $(FLAGS) $(APP_SOURCES) -o $(APLICACAO)

config-test: $(TEST_CONFIG_SOURCES) create-bin
	@echo ...Linkando e produzindo a aplicacao teste para config.hpp
	@$(CC) $(FLAG) $(TEST_CONFIG_SOURCES) -o $(TESTE_CONFIG)

field-test: $(TEST_CAMPO_SOURCES) create-bin
	@echo ...Linkando e produzindo a aplicacao teste para field.hpp
	@$(CC) $(FLAG) $(TEST_CAMPO_SOURCES) -o $(TESTE_CAMPO)

# Roda a aplicação final:
run-app: app
	@echo ...Rodando a aplicacao final
	@echo ================================================================================
	@$(APLICACAO)

# Roda os testes específicos:
run-config-test: config-test
	@echo ...Executando a aplicacao teste para config.hpp
	@echo ================================================================================
	@$(TESTE_CONFIG)
	@echo ================================================================================

run-field-test: field-test
	@echo ...Executando a aplicacao teste para config.hpp
	@echo ================================================================================
	@$(TESTE_CAMPO)
	@echo ================================================================================

