# Campo Minado

## Visão geral

Esse repositório contém a documentação completa do jogo de campo minado desenvolvido por alunos do COLTEC-UFMG como um trabalho de fim de ano em 2025, iniciado em agosto e finalizado em novembro.  

**Envolvidos:** Eduardo, Heitor, Miguel (alunos) e Henrico (professor orientador);  
**Linguagem:** C++;  

## Mecânicas

O jogo gera um mapa de acordo com as especificações do usuário: altura (quant. de linhas), largura (quant. de colunas), quant. de bombas etc. Depois, o jogo continua da maneira usual: O jogador pode escolher uma posição para cavar, e mostrar quantas bombas estão ao redor; ou escolher uma posição para colocar uma bandeira, se ele achar que há uma bomba naquela posição. O jogador ganha se liberar todos os espaços que não tem bombas (usar as bandeiras é critério do jogador). Para cavar e colocar a bandeira, o usuário escreve, respectivamente, os comandos 'dig' e 'flag' (todos os comandos vão estar no final do README, no capítulo **Instruções e referência**).  

A cada comando, uma função para atualizar o tabuleiro é chamada, apagando o texto antes do comando e re-imprimindo o tabuleiro. O usuário pode sair do jogo, voltando para o menu, ao inserir o respectivo comando no terminal, mostrando a pontuação total adquirida por aquele jogo. Do menu, o usuário pode finalizar o programa, mostrando a pontuação total adquirida em tempo de execução. Uma certa quantidade de pontos é adquirida no fim de cada jogo, sendo calculada de acordo com o quanto o jogador avançou no jogo (espaços cavados) e com a dificuldade (proporcional à densidade de bombas: quant. de bombas por quadrado, em média).  

## Algoritmo geral

Antes de gerar as bombas, uma região é sorteada para reservas espaços onde não terá bombas (o tamanho dessa região é decidido nas configurações, e diminui a quantidade de pontos do jogador) para ser mostrada, e como não tem bombas ao redor, o jogo automaticamente vai mostrar as posições ao redor para o usuário ter o número de bombas. Todo esse sistema de já mostrar uma região do campo minado tem como objetivo evitar que o usuário tenha que contar puramente na sorte, por mais que ela seja uma possível ferramenta para se vencer o jogo.  

Na geração do mapa, B bombas são geradas, sendo B o número de bombas escolhido pelo usuário durante a configuração; sendo assim, um laço de repetição roda B vezes gerando uma coluna i e uma coluna j para adicionar uma bomba. Depois da geração das bombas, itera-se por todas as posições da tabela checando, se não tiver bomba nenhuma ali, quantas bombas tem ao redor. Depois disso, o mapa foi completamente gerado e o jogador começa sem saber onde que tem e onde que não tem bombas além daquela posição previamente revelada.  

Depois da geração do mapa, o algorítmo vai separar os inputs do usuário em sub-strings visando descobrir qual dos três comandos foram usados ('exit', 'dig' ou 'flag' - veja mais sobre em **Instruções e referência**), se caso não tenha sido o comando 'exit' (porque nesse caso o jogo vai simplesmente terminar) então ele procura pelos valores 'i' e 'j' correspondentes às linhas e colunas (também separando a string em sub-strings - ou tokens - usando os espaços como delimitadores); vai ter uma checagem para ver se os valores são válidos (se não forem, o input repete) e se for, as subrotinas correspondentes vão ser chamadas usando esses dois valores como parâmetros.  

## Ideias deixadas para trás

Aqui estão compiladas algumas ideias que tivemos no início do projeto na qual, por problemas tanto de planejamento quanto de tempo, não conseguiram serem colocadas em prática.

A mais notável era a ideia de ganhar dinheiro pelos jogos - seria equivalente ao atual sistema de pontuação - e poder comprar *habilidades* e *itens*. A ideia era que essas habilidades e itens poderiam serem coisas como 'revelar posições', 'marcar regiões com bombas' etc.

Outra ideia também descartada foi a criação de um modo de jogo com um campo minado **sem limites**. Ou seja, um campo minado que iria sendo gerado de forma procedural e que o(s) pontos/dinheiro que você ganharia seria proporcional ao quanto que você conseguiu avançar no campo.

A terceira ideia, que era a mais simples, seria armazenar a pontuação ou dinheiro em um arquivo de forma que ela não resetasse no fim de todo programa e até mesmo criar um sistema de login e cadastro para criar um ranking de usuários locais com mais pontos ou dinheiro.

## Arquivos e pastas

O código fonte do jogo está na pasta source, onde o programa principal main.cpp é compilado junto com todos os outros arquivos da pasta para criar a aplicação. A aplicação, assim como os executáveis usados para testar o jogo, é guardada na pasta bin - que é local - enquanto os headers (.hpp) são guardados na pasta include e implementadas por scripts da pasta source.  

A aplicação principal e os executáveis dos testes são compilados usando make e uma Makefile.  

## Intruções e referência

Para rodar a aplicação principal, basta digitar no terminal, enquanto está com a pasta do repositório aberta, o comando:  

`> bin/campo-minado.exe` (`campo-minado.exe` se estiver dentro da pasta bin/),
ou até  
`> make run-app`, caso estiver com o código fonte em mãos e o 'Make' instalado no seu computador - recompila a cada execução.

Os comandos que podem ser usados durante o jogo são:  
`> dig i, j` -> cava do quadrado na linha i e coluna j  
`> flag i, j` -> coloca uma bandeira na linha i e coluna j  
`> exit game` -> Sai do jogo, ganhando os pontos correspondentes à dificuldade e o progresso  

Já no menu, o usuário deve selecionar alguma das 3 opções principais exibidas: *Jogar*, *Configurações* e *Sair*. Se o usuário não fizer nenhuma configuração, o campo minado fica configurado com os valores mínimos:

- campo 5x5;
- 7 bombas;
- região de 9u.a revelada
