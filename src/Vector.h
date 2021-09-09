#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"

namespace MiniEigen {

    class Vector : public Matrix {
        public:
            Vector();
            Vector(int n);
            Vector(int n, std::vector<double> &in);
            Vector(const Vector &vcpy);
    };

    Vector::Vector() {
        nRows = 0;
        nColumns = 0;    
        nElements = 0;
    }

    Vector::Vector(int n) {
        nRows = n;
        nColumns = 1;
        nElements = n;
        std::vector<double> in(n, 0.0);
        matrixData = in;
    }

    Vector::Vector(int n, std::vector<double> &in) {
        nElements = n;
        nRows = n;
        nColumns = 1;
        matrixData = in;
    }

    Vector::Vector(const Vector &cpy) {
        nRows = cpy.nRows;
        nElements = cpy.nElements;
        nColumns = 1;
        matrixData = cpy.matrixData;
    }
}



#endif
