#include <iostream>
#include "Matrix.h"

Matrix::Matrix() {
    nRows = 0;
    nColumns = 0;
    nElements = 0;
    matrixData = vector<double> m(0);
}

Matrix::Matrix(int numRows, int numColumns) {
    nRows = numRows;
    nColumns = numColumns;
    nElements = nRows * nColumns;

    matrixData = new double[nElements];
    
    for (int i = 0; i < nElements; i++) {
        matrixData[i] = 0.0;
    }
}

Matrix();
        Matrix(int numRows, int numColumns);
        Matrix(int numRows, int numColumns, vector<double> input);
        Matrix(const Matrix &matrixCpy);

void Matrix::displayMatrix() {
    for (int i = 0; i < nElements; i++) {
        std::cout << matrixData[i] << " ";
    }
    std::cout << std::endl;
}

int Matrix::numElements() {
    return nElements;
}

int Matrix::numRows() {
    return nRows;
}

int Matrix::numColumns() {
    return nColumns;
}

