//  matrix.h
#ifndef matrix_h
#define matrix_h
#include <cstdio>

using namespace std;
class Matrix{
private:
    int rows;
    int cols;
    int **matrix;

public:
    Matrix();
    Matrix(int size);

    /* Function: getValueAt(int row, int col)
     * input: row and column index of matrix
     * output: value
     */
    int getValueAt(int row, int col);

    /* Function: incrementbyOne(int row, int col)
     * input: row and column index of matrix
     */
    void incrementbyOne(int row, int col);

    ~Matrix();
};

#endif
