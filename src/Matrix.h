#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
namespace MiniEigen {
class Matrix {
    public:
        /* Constructors:
            *** Matricies 
            (1): Default constructor
            (2): Constructor set to m x n
            (3): Constructor set to m x n and takes in
                 pointer to an array of doubles.
            (4): Copy constructor.
            (5): Destructor.
        */
        Matrix();
        Matrix(int numRows, int numColumns);
        Matrix(int numRows, int numColumns, std::vector<double> &input);
        Matrix(const Matrix &matrixCpy);
        // ~Matrix();

        // Ability to resize matrix; returns bool
        // T of F to determine if the resize was
        // successful.
        bool resize(int numRows, int numColumns);

        // Returns value at m x n
        double retrieveElement(int row, int column);

        // Sets element at m x n to input value.
        void setElement(int row, int column, double in); 

        // Visual display of matrix.
        void displayMatrix();
        
        // Retrieve private members.
        int numRows();
        int numColumns();
        int numElements();

        // OStream overloading:
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mtx);

        // // Basic Matrix Manipulation. (Matrix by Matrix)

        friend Matrix operator+(Matrix &m1, Matrix &m2);
        friend Matrix operator-(Matrix &m1, Matrix &m2);
        friend Matrix operator*(Matrix &m1, Matrix &m2);

        // // Scalar * Matrix Operation

        friend Matrix operator*(Matrix &m1, double scalar);
        friend Matrix operator*(double scalar, Matrix &m1);
        
        // Access element of MxN Matrix
        
        double at(int row, int column);

        
    protected:
        std::vector<double> matrixData;
        int nRows, nColumns, nElements;
};
}

#endif      
