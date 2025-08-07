# Como que o jogo vai funcionar
~Eduardo

## Gerando o mapa
O jogo vai começar gerando o mapa, para isso, pensei em começar pegando um elemento aleatório no campo, e gerar um número aleatório para o tanto que bombas que vão ser
colocadas ao redor. Depois de decidir quantas bombas vão ser colocadas, coloca-se as bombas. Depois disso, vamos usar um algorítmo de BFS, onde o código vai criar uma 
fila (queue) onde vão ser armazenados as posições onde falta gerar um número de bombas; dessa forma, os primeiros quadradinhos vão ser os primeiros a serem gerados.
Quando chegar na vez de um quadradinho ter o número de bombas gerado, o código checa se isso pode realmente acontecer: o número de bombas ao redor do quadradinho é
menor ou igual ao número sorteado? Se sim, o código vai gerar a quantidade de bombas que falta para alcançar o número sorteado; caso contrário, o número vai ser
simplesmente o número de bombas que tem naquele momento. Esse processo repete-se até preencher todo o campo, cuidando cuidado, é claro, para as posições ao redor do
quadradinho onde não tem quadradinhos (se um quadradinho está no topo, não há nenhum acima dele), e para os quadradinhos que já tem um número sorteado ou que já tem
uma bomba. Cada quadradinho vai ter uma lista de referências para os quadradinhos vizinhos, e cada quadradinho vai também ter um valor que representa o número de
bombas caso seja maior ou igual a zero, se tem uma bomba (quando valer -1) ou se ainda não teve o número de bombas gerado (quando for NULL). Esse processo vai criar o
que chamamos de árvore de dados, e é por isso que o algorítmo de BFS vai ser eficiente.

## O jogo em si
Depois da geração do mapa, o usuário vai começar a selecionar quadradinhos onde ele quer cavar ou colocar a bandeira, perde assim que cavar em uma posição onde há uma
bomba, e ganha se colocar as bandeiras em todos os lugares que tem bombas e quando liberar todos os espaços onde não tem bombas. Para isso, o jogo tem duas opções que
nós ainda não decidimos:
  1. Pegar um input do teclado para a posição onde ele quer fazer algumas das duas ações,
  2. Ele usa o mouse para poder mostrar onde realizar alguma das duas opções

