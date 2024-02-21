//
// Created by youngliqui on 20.02.2024.
//

#include "Matrix.h"

#include <utility>
#include "vector"
#include "iostream"

using namespace std;

Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
}

Matrix::~Matrix() = default;

int Matrix::getColumns() const {
    return columns;
}

int Matrix::getRows() const {
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
            for (int j = firstPos + 1; j < secondPos; j++) {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}

/**
 * Отображает матрицу в консоли
 */
void Matrix::printMatrix() const {
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++) {
            cout << matrix.at(rowIndex)[columnIndex] << " ";
        }
        cout << endl;
    }
}

/**
 * Заменяет vector matrix на другой вектор, переданный в аргументах.
 * std::move(matrix) гарантирует перемещение значения matrix в this->matrix без лишних копирований.
 * @param matrix
 */
void Matrix::setMatrix(std::vector<std::vector<int>> matrix) {
    this->matrix = std::move(matrix);
}

