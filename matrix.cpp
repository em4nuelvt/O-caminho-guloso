#include "matrix.hpp"
// definição das funções
void decisaoDesaida(int **matrix, short int *i, short int *j, short int nrows,short int ncols, int *acm) {
  // verificando se é a ultima linha para andar para a direita logo de cara
  if (*i == nrows - 1) { //é -1 pq o a iteração de i começa no 0
    moveRight(matrix, i, j,acm);
    return;
  }
  //definindo variveis de controle/decisao
  short int lastCol, lastRow;
  lastCol=ncols-1;
  lastRow=nrows-1;
  int maiorAtual;
  short int decisao; 
  /* obs.: as decisões sao tomadas seguindo a seguinte legenda:
  1- move para esquerda;
  2- move para a diagonal inferior esquerda;
  3- move para baixo;
  4- move para a diagonal inferior direita;
  5- move para a direita */

  if(*j==0&&*i!=lastRow){//caso da posição estar na primeira coluna mas nao na primeira linha:
    maiorAtual=0;
    if(matrix[*i+1][*j]>maiorAtual){
      maiorAtual=matrix[*i+1][*j];
      decisao=3;
    }
    if(matrix[*i][*j+1]>maiorAtual){
      maiorAtual=matrix[*i][*j+1];
      decisao=5;
    }
    if(matrix[*i+1][*j+1]>=maiorAtual){
      maiorAtual=matrix[*i+1][*j+1];
      decisao=4;
    }
    redirecionaDecisao(decisao, matrix, i,j,acm);
    return;
  }
  if(*j==lastCol){  //caso posição seja na última coluna
    maiorAtual=0;
    if(matrix[*i][*j-1]>maiorAtual){
      maiorAtual=matrix[*i][*j-1];
      decisao=1;
    }
    if(matrix[*i+1][*j-1]>maiorAtual){
      maiorAtual=matrix[*i+1][*j-1];
      decisao=2;
    }
    if(matrix[*i+1][*j]>=maiorAtual){
      maiorAtual=matrix[*i+1][*j];
      decisao=3;
    }
    redirecionaDecisao(decisao, matrix, i,j,acm);
    return;
  }
  //caso de movimentação geral: 
  maiorAtual=0;
  if(matrix[*i][*j-1]>=maiorAtual){
    maiorAtual=matrix[*i][*j-1];
    decisao=1;
  }
  if(matrix[*i+1][*j-1]>=maiorAtual){
    maiorAtual=matrix[*i+1][*j-1];
    decisao=2;
  }
  if(matrix[*i+1][*j]>=maiorAtual){
    maiorAtual=matrix[*i+1][*j];
    decisao=3;
  }
  if(matrix[*i][*j+1]>=maiorAtual){
    maiorAtual=matrix[*i][*j+1];
    decisao=5;
  }
  if(matrix[*i+1][*j+1]>=maiorAtual){
    maiorAtual=matrix[*i+1][*j+1];
    decisao=4;
  }
  redirecionaDecisao(decisao, matrix, i,j,acm);
  return;
}

void redirecionaDecisao(short int decisao,int** matrix, short int* i, short int* j, int *acm){
  switch (decisao)
  {
  case 1:
    moveLeft(matrix, i, j,acm);
    break;
  case 2:
    moveLeftDiagonal(matrix, i, j,acm);
    break;
  case 3:
    moveDown(matrix, i, j,acm);
    break;
  case 4:
    moveRightDiagonal(matrix, i, j,acm);
    break;
  case 5:
    moveRight(matrix, i, j,acm);
    break;
  }
  return;
}

void moveLeft(int **matrix, short int *i, short int *j, int *acm) {
  *acm= *acm +matrix[*i][*j];
  matrix[*i][*j]=-1;
  *j = *j - 1;
  cout << "posição: " << matrix[*i][*j] << endl;
}
void moveRight(int **matrix, short int *i, short int *j, int *acm) {
  *acm= *acm +matrix[*i][*j];
  matrix[*i][*j]=-1;
  *j = *j + 1;
  cout << "posição: " << matrix[*i][*j] << endl;


}
void moveRightDiagonal(int **matrix, short int *i, short int *j, int *acm) {
  *acm= *acm +matrix[*i][*j];
  matrix[*i][*j]=-1;
  *i = *i + 1;
  *j = *j + 1;
  cout << "posição: " << matrix[*i][*j] << endl;
}
void moveLeftDiagonal(int **matrix, short int *i, short int *j, int *acm) {
  *acm= *acm +matrix[*i][*j];
  matrix[*i][*j]=-1;
  *i = *i + 1;
  *j = *j - 1;
  cout << "posição: " << matrix[*i][*j] << endl;

}
void moveDown(int **matrix, short int *i, short int *j, int *acm) {
  *acm= *acm +matrix[*i][*j];
  matrix[*i][*j]=-1;
  *i = *i + 1;
  cout << "posição: " << matrix[*i][*j] << endl;
}
void printMatrix(int**matrix, short int rows, short int cols){
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if(matrix[i][j]==-1){
        cout<<"[ X ]\t";
      }else{
        cout << "["<<matrix[i][j]<<"]" << "\t";
      }
    }
    cout << endl;
  } 
}
