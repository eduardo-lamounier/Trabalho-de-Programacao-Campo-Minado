# Visão Geral

Esse repositório contém a documentação completa do jogo de campo minado desenvolvido por alunos do COLTEC-UFMG como um trabalho de fim de ano em 2025, iniciado em agosto e finalizado em novembro.  

**Envolvidos:** Eduardo, Heitor, Miguel (alunos) e Henrico (professor orientador);  
**Linguagem:** C++;  

# Sobre o jogo
O jogo gera um mapa de acordo com as especificações do usuário: altura (quant. de linhas), largura (quant. de colunas), quant. de bombas etc. Depois, o jogo continua da maneira usual: O jogador pode escolher uma posição para cavar, e mostrar quantas bombas são ao redor; ou escolher uma posição para colocar uma bandeira, se ele achar que há uma bomba naquela posição. O jogador ganha se liberar todos os espaços que não tem bombas (usar as bandeiras é critério do jogador). Para cavar e colocar a bandeira, o usuário escreve, respectivamente, os comandos 'dig' e 'flag':  

dig i, j -> cava do quadrado na linha i e coluna j  
flag i, j -> coloca uma bandeira na linha i e coluna j  

A cada comando, uma função para atualizar o tabuleiro é chamada, apagando o texto antes do comando e re-imprimindo o tabuleiro. O usuário pode sair do jogo, finalizando o programa, a qualquer momento da execução; ao inserir o comando 'exit' no terminal, mostrando a pontuação total adquirida durante o tempo de execução. Uma certa quant. de pontos é adquirida no fim de cada jogo, sendo calculada de acordo com o quanto o jogador avançou no jogo (espaços cavados) e com a dificuldade (proporcional à densidade de bombas: quant. de bombas por quadrado, em média).  

# Algoritmo geral
Na geração do mapa, B bombas são geradas, sendo B o número de bombas escolhido pelo usuário durante a configuração; sendo assim, um laço de repetição roda B vezes gerando uma coluna i e uma coluna j para adicionar uma bomba, atribuindo o valor 'bombsNearby' (que mostra quantas bombas há por perto daquela posição) naquela posição como -1 para simbolizar isso. Depois da geração das bombas, itera-se por todas as posições da tabela checando, se não tiver bomba nenhuma ali, quantas bombas tem ao redor, e atribuindo esse valor a 'bombsNearby'. Depois disso, o mapa foi completamente gerado, e como a propriedade 'shown' (simboliza se o valor naquela posição está sendo exibido) está atribuida como false para todas as posições, o jogador começa sem saber onde que tem e onde que não tem bombas.  

Para iniciar o jogo, uma posição que tenha 0 bombas ao redor é sorteada para ser mostrada (i.e. 'shown' passa a ser true), e como não tem bombas algumas ao redor, o jogo automáticamente vai mostrar as posições ao redor para o usuário ter os números de bombas. Isso deve ser feito para evitar que o usuário tenha que contar puramente na sorte, por mais que ela seja uma possível ferramenta para ser vencer o jogo. Depois disso, o algorítmo vai usar funções da linguagem para separar os inputs do usuário em sub-strings visando descobrir qual dos três comandos foram usados ('exit', 'dig' ou 'flag'), se caso não tenha sido o comando 'exit' (porque nesse caso o jogo vai simplesmente terminar) então ele procura pelos valores 'i' e 'j' correspondentes às linhas e colunas (também separando a string em sub-strings - ou tokens - usando os espaços como delimitadores); vai ter uma checagem para ver se os valores são válidos (se não forem, o input repete) e se for, as subrotinas correspondentes vão ser chamadas usando esses dois valores como parâmetros.  

Depois da geração das bombas, itera-se por todos os quadradinhos (posiçõe  s com bombas são puladas) mapeando quantas bombas há ao redor; depois, todas as posições tem a propriedade 'shown' atribuida como false, o que quer dizer que inicialmente, nenhuma posição tem seu valor exibido.  

