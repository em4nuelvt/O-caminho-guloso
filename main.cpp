#include "matrix.hpp"
#include <fstream>
#include <iostream>

int main() { // declaração de variáveis
  ifstream file;
  short int rows, cols;
  int **matrix;
  short int contMatrix=1;
  int acm=0;
  // variaveis de iniciais de controle do deslocameto dos eixos das matrizes
  short int x = 0, y = 0;
  cout<<"Insira a linha que ira começar a execução: ";
  cin>>x;
  cout<<"Insira a coluna que ira começar a execução: ";
  cin>>y;
  // abrindo o arquivo das matrizes
  file.open("input.data", std::ios::in);
  if (!file) {
    cerr << "Não foi possível abrir o arquivo";
    return 0;
  }

  // setando o número de linhas e colunas
  file >> rows >> cols;

  // alocando a matriz
  matrix = (int **)malloc(sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(sizeof(int) * cols);
  }

  //trabalhando com cada matriz
  while(!file.fail()){
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        file >> matrix[i][j];
        if(file.fail())
          break;
      }
    }
    if(file.fail()){
      break;
    }else{
      cout<<"Matriz: "<<contMatrix<<endl;
      if(contMatrix>1){
        x=0,y=0;
      }
      cout << "posição inicial : " << matrix[x][y] << endl;
      while(!(y==cols-1&&x==rows-1)){
        decisaoDesaida(matrix, &x, &y, rows, cols,&acm);
        cout<<x<<","<<y<<endl;
      }
      acm=acm+ matrix[x][y]; //soma o valor da ultima posição
      cout<<"soma com a matriz " <<contMatrix<<": "<<acm<<endl<<endl;
      
      //imprimindo a matriz com os caminhos marcados com -1:
      matrix[x][y]=-1;
      printMatrix(matrix,rows,cols);
      x=0,y=0;//define a primeira posição para a próxima matriz
      contMatrix++; 
    }

    cout<<endl<<endl;
  }
  x=0,y=0;

  cout<<"Total do caminho: "<<acm<<endl;

  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  cout << endl;
  free(matrix);
  // fechando o arquivo
  file.close();
  return 0;
}
