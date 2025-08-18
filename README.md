# Visão Geral

Esse repositório contém a documentação completa do jogo de campo minado desenvolvido por alunos do COLTEC-UFMG como um trabalho de fim de ano em 2025, iniciado em agosto e finalizado em novembro.

**Envolvidos:** Eduardo Lamounier, Heitor Freitas, Miguel Peterson (alunos) e Henrico Barbosa (professor orientador);
**Turma:** 104B;  
**Linguagem:** C++;

# Sobre o jogo
O jogo gera um mapa de acordo com as especificações do usuário: altura (quant. de linhas), largura (quant. de colunas), quant. de bombas etc. Depois, o jogo continua da maneira usual: O jogador pode escolher uma posição para cavar, e mostrar quantas bombas são ao redor; ou escolher uma posição para colocar uma bandeira, se ele achar que há uma bomba naquela posição. O jogador ganha se liberar todos os espaços que não tem bombas (usar as bandeiras é critério do jogador). Para cavar e colocar a bandeira, usa-se, respectivamente, os comandos 'dig' e 'flag':  

dig i, j -> cava do quadrado na linha i e coluna j  
flag i, j -> coloca uma bandeira na linha i e coluna j  

A cada comando, uma função para atualizar o tabuleiro é chamada, apagando o texto antes do comando e re-imprimindo o tabuleiro. O usuário pode sair do jogo, finalizando o programa, a qualquer momento da execução; ao inserir o comando 'exit' no terminal, mostrando a pontuação total adquirida durante o tempo de execução. Uma certa quant. de pontos é adquirida no fim de cada jogo, sendo calculada de acordo com o quanto o jogador avançou no jogo (espaços cavados) e com a dificuldade (proporcional à densidade das bomba: quant. de bombas por quadrado, em média).  

# Algoritmo geral
[...]  
