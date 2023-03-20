# Matriz Caminho Guloso
Trabalho proposto da disciplina de Algoritmos e Estruturas de Dados I.

  A proposta foi: 

  1. Criar um sistema que leia K matrizes quadradas no tamanho NxN.
  
  2. Seu programa deve enumerá-las, de forma a deixa-las organizadas para processamento. 

  3. Partindo da primeira matriz, você deve iniciar de um ponto preestabelecido, esse pode ser fornecido pelo usuário ou estar contido em arquivos extras de   configuração. Não é permitido definir diretamente no código. 

  4. A partir da primeira matriz, você tem como regras: 
     * avançar para a próxima coluna; 
     * retroceder para coluna anterior; 
     *  saltar para a linha de   baixo; 
     * ir em diagonal para baixo. Todas  essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já           processada. 

  5. Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma      regra para adotar sempre uma mesma decisão de caminhamento. 

  6. Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado. 


## Visão Geral
Algoritmo guloso é uma técnica de projetos de algoritmos que visa solucionar problemas a partir de uma solução local, a fim de encontrar uma boa solução global. Dessa maneira, as decisões sao tomadas com base nas informações obtidas na iteração corrente. Neste algoritimo do caminho guloso, a análise local é feita a partir de cada iteração que analisa a posição corrente da matriz e encontra o melhor caminho para a iteração seguinte, sem se preocupar com iterações passadas e todas as iterações que virão, exceto a seguinte. Dessa forma, ao fim da execução do algoritmo, cada caminho local converge para a solução global que é a soma dos caminhos das matrizes.

## Entrada
* Durante a execução, deve ser informado qual a posição inicial na primeira matriz ([linha][coluna]) .
* A entrada principal do código consiste em um arquivo que apresenta matrizes com valores inteiros separados por espaços e a dimensão padrão delas. Esse arquivo apresenta um formato específico, mas com valores aleatórios, gerados por um algoritmo disponibilizado pelo professor.


* O arquivo segue o formato abaixo

     ![image](https://user-images.githubusercontent.com/64996505/226121191-c0277b02-4034-4c2d-a01b-0a440e3e4904.png)

## Implementação
A solução foi implementada em C++ e segue os seguintes passos:

Como o número de matrizes não é estipulado e as dimensões são variáveis, cada matriz lida do arquivo é armazenada temporariamente em uma matriz de números inteiros alocada dinamicamente usando a função malloc(). A dimensão das matrizes está contida na primeira linha do arquivo *input.data*, portanto o espaço de memória alocado depende desse valor que é armazenado nas variáveis: *rows* e *cols*.

A primeira matriz tem a posição de início informada pelo usuário. A posição (linha,coluna) é armazenada nas variáveis x,y, que também são utilizadas como controle de posição em cada iteração.

O algoritmo é executado dentro de dois loops: um loop de leitura que faz iterações até que a leitura do arquivo chegue ao fim (!file.fail()) e um segundo que caminha dentro de cada matriz e realiza operações até encontrar a posição final(matrix[rows-1][cols-1]).

Em cada iteração algoritmo é representado pelos seguintes passos:

  Loop externo(leitura):
  * Leitura do arquivo para atribuição da matriz da iteração corrente;

    Loop interno (operações com cada matriz):

    * Determinar se a posição da iteração atual se encaixa em algum dos casos especiais:
      * Primeira coluna: não pode andar para esquerda, nem para diagonal esquerda;
      * Ultima coluna: nao pode andar para direita, nem para diagonal direita;
      * Ultima linha: único movimento possível é direita.
       
    * Verificar os movimentos possíveis e definir o próximo passo com uma função de decisão que compara o valor a posição atual e redireciona para um dos seguintes movimentos:
      * Direita [i][j+1]
      * Diagonal inferior direita [i+1][j+1]
      * Diagonal inferior esquerda [i+1][j-1]
      * Baixo [i][j+1]
      * Esquerda [i][j-1]
       
       Cada movimento representa uma função de caminhamento na matriz. Portanto, a função de decisão identifica a posição que apresenta o maior valor dentre os possíveis movimentos e redireciona para o caminho correto. Isso acontece através da chamada de alguma dessas funções de movimetação.
      
    * Ao caminhar pela matriz, uma variável acumuladora (acm) acumula a soma dos valores das posições de cada iteração para exibir, ao fim do algoritmo, a soma total dos caminhos.
    
    * O valor da posição obtida é substituído por -1 para garantir que o algoritmo não volte na posição em iterações futuras na mesma matriz.
    
    * Ao chegar no fim de uma matriz, a variável acumuladora é exibida com a soma do valor total até a última iteração, a matriz é impressa na tela substuindo as posições que apresentavam "-1" por "X", indicando o caminho percorrido.
    
    * Parte para a próxima matriz na posição 0,0 e continua a iteração do loop externo até o fim do arquivo.

    Vale ressaltar que em situações nas quais  o algoritmo encontra posições de mesmo valor para seguir um caminho, a prioridade é sempre prosseguir em linhas e colunas, dessa forma a prioridade de movimentação é: diagonal inferior direita; direita; baixo; diagonal inferior esquerda; esquerda.


    Exemplo de matriz de saída com o caminho marcado:
    
      ![image](https://user-images.githubusercontent.com/64996505/226490194-b64609a6-e780-431a-92ab-70a339d192f7.png)


## Compilação e Execução

A estrutura árvore disponibilizada possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

Os testes de execução foram gerados aleatoriamente, partindo do código que gerou o arquivo "input.data" presente no repositório do projeto.
    


