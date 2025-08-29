# Compilador e flags:
CC = g++
FLAGS = -Wall -Iinclude

# Nomes dos executáveis:
APLICACAO = app.exe
TESTE_CONFIG = configTest.exe

# Fontes papra cada executável:
APP_SOURCES = source/main.cpp source/config.cpp
TESTE_CONFIG_SOURCES = testing/configTest.cpp source/config.cpp

# Target padrão: Compila tudo:
all: app config-test

# Linka e produz as aplicações:
app: $(APP_SOURCES)
	@echo "Linkando e produzindo a aplicacao final"
	$(CC) $(FLAGS) $(APP_SOURCES) -o $(APLICACAO)

config-test: $(TESTE_CONFIG_SOURCES)
	@echo "Linkando e produzindo a aplicacao teste para config.hpp"
	$(CC) $(FLAG) $(TESTE_CONFIG_SOURCES) -o $(TESTE_CONFIG)

# Roda (necessita compilação) algum dos executáveis:
run-app: app
	$(APLICACAO)

run-config-test: config-test
	$(TESTE_CONFIG)

# Remove todos os elementos (com exceção dos arquivos source):
clean:
	@echo "Removendo tudo com excecao dos arquivos source"
	rm -f $(APLICACAO) $(TESTE_CONFIG)
