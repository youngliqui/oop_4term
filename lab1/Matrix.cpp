//
// Created by youngliqui on 20.02.2024.
//

#include "Matrix.h"
#include "vector"
#include "iostream"

using namespace std;

Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
}

Matrix::~Matrix() = default;

int Matrix::getColumns() {
    return columns;
}

int Matrix::getRows() {
    return rows;
}

/**
 * Вычисляет сумму элементов матрицы, располложенных между первым и вторым положительными элементами
 * каждой строки.
 * @return Сумма эл-ов между 1 и 2 положительными элементами каждой строки матрицы.
 */
long Matrix::getSumBetweenFirstAndSecondPositive() {
    long sum = 0;
    for (int i = 0; i < rows; i++) {
        int firstPos = -1;
        int secondPos = -1;

        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] > 0) {
                if (firstPos == -1) {
                    firstPos = j;
                } else {
                    secondPos = j;
                    break;
                }
            }
        }

        if (firstPos != -1 && secondPos != -1) {
            for (int j = 0; j < rows; j++) {

            }
        }
    }

    return sum;
}

/**
 * Отображает матрицу в консоли
 */
void Matrix::printMatrix() {
    for (int i = 0; i < rows; i++) {
        cout << endl;
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
    }
}

