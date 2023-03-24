# Matriz Caminho Guloso
Trabalho proposto da disciplina de Algoritmos e Estruturas de Dados I.

  A proposta foi: 

  1. Criar um sistema que leia K matrizes quadradas no tamanho NxN.
  
  2. O programa deve enumerá-las, de forma a deixa-las organizadas para processamento. 

  3. Partindo da primeira matriz, você deve iniciar de um ponto preestabelecido, esse pode ser fornecido pelo usuário ou estar contido em arquivos extras de   configuração. Não é permitido definir diretamente no código. 

  4. A partir da primeira matriz, você tem como regras: 
     * avançar para a próxima coluna; 
     * retroceder para coluna anterior;         
     *  saltar para a linha de   baixo; 
     * ir em diagonal para baixo. Todas  essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já           processada. 

  5. Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma      regra para adotar sempre uma mesma decisão de caminhamento. 

  6. Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado. 


## Visão Geral
Algoritmo guloso é uma técnica de projetos de algoritmos que visa solucionar problemas a partir de uma solução local, a fim de encontrar uma boa solução global. Dessa maneira, as decisões sao tomadas com base nas informações obtidas na iteração corrente. Neste algoritmo do caminho guloso, a análise local é feita a partir de cada iteração que analisa a posição corrente da matriz e encontra o melhor caminho para a iteração seguinte, sem se preocupar com iterações passadas e todas as iterações que virão, exceto a seguinte. Dessa forma, ao fim da execução do algoritmo, cada caminho local converge para a solução global que é a soma dos caminhos das matrizes. Portanto, para as matrizes do problema em questão, voltar linhas da matriz, que seria equivalente a "andar para trás" não é uma opção viável.

A cada posição de uma matriz, o caminhamento segue um dos casos de movimentação de acordo com a posição que a iteração se encontra:

* Meio da matriz: pode seguir em todas as direções, exceto voltar linhas.
* Primeira Coluna: segue somente para direita, para baixo ou para a diagonal inferior direita.
* Última coluna: segue somente para esquerda, para baixo ou para a diagonal inferior esquerda.
* Última linha: segue à direita.

  ![image](https://user-images.githubusercontent.com/64996505/227387333-1b32197a-115b-441b-aa65-f954d9806daf.png)
  ![image](https://user-images.githubusercontent.com/64996505/227387536-5af73f84-7716-4657-82c0-4403403f4749.png)
  ![image](https://user-images.githubusercontent.com/64996505/227387749-57fd15cd-1c59-4e47-8fa2-a67ca6d457c9.png)
  ![image](https://user-images.githubusercontent.com/64996505/227387879-2047c707-0767-4d73-9df5-e1cf49eb5f52.png)

## Entrada
* Durante a execução, deve ser informado qual a posição inicial na primeira matriz ([linha][coluna]) .
* A entrada principal do código consiste em um arquivo que apresenta matrizes com valores inteiros separados por espaços e a dimensão padrão delas. Esse arquivo apresenta um formato específico, mas com valores aleatórios, gerados por um algoritmo disponibilizado pelo professor.


* O arquivo segue o formato abaixo

     ![image](https://user-images.githubusercontent.com/64996505/226121191-c0277b02-4034-4c2d-a01b-0a440e3e4904.png)

Observação: nesse exemplo há somente duas matrizes. Entretanto, o número de matrizes do arquivo de teste não é fixo, pode ser somente uma ou até mesmo milhares.

## Implementação
A solução foi implementada em C++ e segue os seguintes passos:

Como o número de matrizes não é estipulado e as dimensões são variáveis, cada matriz lida do arquivo é armazenada temporariamente em uma matriz de números inteiros alocada dinamicamente usando a função malloc(). A dimensão das matrizes está contida na primeira linha do arquivo *input.data*, portanto o espaço de memória alocado depende desse valor que é armazenado nas variáveis: *rows* e *cols*. A leitura é feita a partir de um objeto ifstream importado da biblioteca fstream.

A primeira matriz tem a posição de início informada pelo usuário. A posição (linha,coluna) é armazenada nas variáveis x,y, que também são utilizadas como controle de posição em cada iteração.

O algoritmo é executado dentro de dois loops: um loop de leitura que faz iterações até que a leitura do arquivo chegue ao fim (!file.fail()) e um segundo que caminha dentro de cada matriz e realiza operações até encontrar a posição final(matrix[rows-1][cols-1]).

Em cada iteração algoritmo é representado pelos seguintes passos:

  Loop externo(leitura):
  * Leitura do arquivo para atribuição da matriz da iteração corrente;

    Loop interno (operações com cada matriz):

    * Determinar se a posição da iteração atual se encaixa em algum dos casos especiais:
      * Primeira coluna: não pode andar para esquerda, nem para diagonal esquerda;
      * Ultima coluna: não pode andar para direita, nem para diagonal direita;
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


    Exemplo de matriz de saída com o caminho marcado ao fim do loop:
    
      ![image](https://user-images.githubusercontent.com/64996505/226490194-b64609a6-e780-431a-92ab-70a339d192f7.png)


## Teste

* Para verificar a solução do algoritmo segue um caso de teste para exemplificação do funcionamento. 

  A seguinte matriz foi utilizada como entrada:

  ![image](https://user-images.githubusercontent.com/64996505/227378383-dfb76215-4973-4e59-804f-84a76f11e852.png)

* A posição inicial (linha,coluna) definida para matriz foi a posição (1,2).

  ![image](https://user-images.githubusercontent.com/64996505/227378029-b2911f69-5ee4-499f-896f-615a51cde4b4.png)

* A cada iteração, a posição corrente é impressa com o seu valor e, ao fim do laço,a soma dos valores de cada posição do caminho também é impresso, como na imagem:

  ![image](https://user-images.githubusercontent.com/64996505/227378167-8bb2a2bd-56ac-4d28-a43f-23f23798daef.png)

* Somando os valores das posições (253+762+903+707+564+545+814+806+193+509+893+263) o resultado obtido é 7212, exatamente o valor mostrado na execução do teste.

* Em seguida a matriz é impressa com o caminho percorrido:

  ![image](https://user-images.githubusercontent.com/64996505/227378252-d4614bc9-36bc-426a-b4e8-daf6e539048e.png)


## Compilação e Execução

O projeto possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

Os testes de execução foram gerados aleatoriamente, partindo do código que gerou o arquivo "input.data" presente no repositório do projeto.










