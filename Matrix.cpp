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

Matrix::Matrix(int numRows, int numColumns, std::vector<double> &input) {
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

Matrix operator+(Matrix &m1, Matrix &m2) {
    int resRows = m1.nRows;
    int resColumns = m1.nColumns;
    int resElements = m1.nElements;
    std::vector<double> resvec(resElements);
    for (int i = 0; i < resElements; i++) {
        resvec[i] = m1.matrixData[i] + m2.matrixData[i];
    }
    Matrix res = Matrix(resRows, resColumns, resvec);
    return res;
}

// friend Matrix operator-(Matrix &m1, Matrix &m2);
// friend Matrix operator*(Matrix &m1, Matrix &m2);
// friend Matrix operator/(Matrix &m1, Matrix &m2);