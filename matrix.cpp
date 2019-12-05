//  matrix.cpp
#include <iostream>
#include "matrix.h"
using namespace std;
Matrix::Matrix() {
    rows = cols = 4;
    matrix = new int*[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;
    }
}

Matrix::Matrix(int size){
    rows = cols = size;
    matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;
    }
}

int Matrix::getValueAt(int row, int col){
    return matrix[row][col];
}

void Matrix::incrementbyOne(int row, int col){
    matrix[row][col] = matrix[row][col] + 1;
}

Matrix::~Matrix(){
    for(int i = 0; i < rows; i++)
        delete matrix[i];
    delete matrix;
}
