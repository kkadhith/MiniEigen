#include <iostream>
#include <vector>
#include "Matrix.h"


Matrix::Matrix() {
    nRows = 0;
    nColumns = 0;
    nElements = 0;
    std::vector<double> m;
    matrixData = m;
}

Matrix::Matrix(int numRows, int numColumns) {
    nRows = numRows;
    nColumns = numColumns;
    nElements = nRows * nColumns;

    std::vector<double> data(nElements, 0.0);
    matrixData = data;
}

Matrix::Matrix(int numRows, int numColumns, std::vector<double> input) {
    nRows = numRows;
    nColumns = numColumns;
    nElements = nRows * nColumns;
    matrixData = input;
}

Matrix::Matrix(const Matrix &matrixCpy) {
    nRows = matrixCpy.nRows;
    nColumns = matrixCpy.nColumns;
    nElements = matrixCpy.nElements;
    matrixData = matrixCpy.matrixData;
}

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

std::ostream& operator<<(std::ostream& os, const Matrix& mtx) {
    for (int i = 0; i < mtx.nElements - 1; i++) {
        os << mtx.matrixData[i] << " ";
    }
    os << mtx.matrixData[mtx.nElements-1] << std::endl;
    return os;
}

