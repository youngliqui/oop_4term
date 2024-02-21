//
// Created by youngliqui on 20.02.2024.
//
#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    int rowsNum = 0;
    int columnsNum = 0;

    cout << "Creating matrix:" << endl
         << "number of rows:";
    cin >> rowsNum;

    cout << "number of columns:";
    cin >> columnsNum;

    Matrix* matrix = new Matrix(rowsNum, columnsNum);

    vector<vector<int>> inputVector(rowsNum, vector<int>(columnsNum));
    cout << "enter elements:" << endl;
    for (int i = 0; i < rowsNum; i++) {
        for (int j = 0; j < columnsNum; j++) {
            int inputElement;
            cin >> inputElement;
            inputVector[i][j] = inputElement;
        }
        cout << endl;
    }
    matrix->setMatrix(inputVector);

    cout << "matrix:" << endl;
    matrix->printMatrix();
    cout << endl << "Sum: " << matrix->getSumBetweenFirstAndSecondPositive();

    delete matrix;

    return 0;
}