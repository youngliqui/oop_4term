//
// Created by youngliqui on 20.02.2024.
//

#ifndef OOP_4TERM_MATRIX_H
#define OOP_4TERM_MATRIX_H

#endif //OOP_4TERM_MATRIX_H

#include <vector>

class Matrix {
public:
    Matrix(int rows, int cols);
    ~Matrix();
    int getRows() const;
    int getColumns() const;
    void setMatrix(std::vector<std::vector<int>>& matrix);
    long getSumBetweenFirstAndSecondPositive();
    void printMatrix() const;

private:
    int rows;
    int columns;
    std::vector<std::vector<int>> matrix;
};
