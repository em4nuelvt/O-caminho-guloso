#ifndef _MATRIX_HPP
#define _MATRIX_HPP
#include <iostream>
using namespace std;

//declaração das funções
void decisaoDesaida(int** matrix, short int *i,short int* j, short int nrows, short int ncols, int *acm);
void redirecionaDecisao(short int decisao,int** matrix, short int* i, short int* j, int *acm);
void moveLeft(int** matrix, short int* i, short int* j, int *acm);
void moveRight(int** matrix, short int* i, short int* j, int *acm);
void moveRightDiagonal(int** matrix, short int* i, short int* j, int *acm);
void moveLeftDiagonal(int** matrix, short int* i, short int* j, int *acm);
void moveDown(int** matrix, short int* i, short int* j, int *acm);
void printMatrix(int**matrix, short int rows, short int cols);
#endif