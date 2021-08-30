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
    int n = 0;
    for (int i = 0; i < mtx.nElements; i++) {
        int j = i+1;
        os << mtx.matrixData[i] << " ";
        j = j / mtx.nColumns;
        if (j == n+1) {
            os << std::endl;
            n++;
        }
    }
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

Matrix operator-(Matrix &m1, Matrix &m2) {
    int resRows = m1.nRows;
    int resColumns = m1.nColumns;
    int resElements = m1.nElements;
    std::vector<double> resvec(resElements);
    for (int i = 0; i < resElements; i++) {
        resvec[i] = m1.matrixData[i] - m2.matrixData[i];
    }
    Matrix res = Matrix(resRows, resColumns, resvec);
    return res;
}

Matrix operator*(Matrix &m1, Matrix &m2) {
    int resRows = m1.nRows;
    int resColumns = m2.nColumns;
    int resElements = resRows * resColumns;
    std::vector<double> resvec(resElements);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nColumns; j++) {
            double element = 0.0; 
            for (int k = 0; k < m1.nColumns; k++) {
                int index1 = (i * m1.nColumns) + k;
                int index2 = (k * m2.nColumns) + j;

                element += (m1.matrixData[index1] * m2.matrixData[index2]); 
            }
            int index = (i * m2.nColumns) + j;
            resvec[index] = element;
        }
    }
    Matrix res = Matrix(resRows, resColumns, resvec);
    return res;
}

Matrix operator*(Matrix &m1, double scalar) {
    std::vector<double> resVec(m1.nElements);

    for (int i = 0; i < m1.nElements; i++) {
        resVec[i] = m1.matrixData[i] * scalar;
    }
    Matrix res = Matrix(m1.nRows, m1.nColumns, resVec);
    return res;
}