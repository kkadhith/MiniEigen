#include <iostream>
#include "Matrix.h"


Matrix::Matrix(int numRows, int numColumns) {
    nRows = numRows;
    nColumns = numColumns;
    nElements = nRows * nColumns;

    matrixData = new double[nElements];
    
    for (int i = 0; i < nElements; i++) {
        matrixData[i] = 0.0;
    }
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

