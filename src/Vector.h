#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"

namespace MiniEigen {

    class Vector : public Matrix {
        public:
            Vector();
            Vector(int n);
            // Vector(int n, std::vector<double> in);
            // Vector(const Vector &vcpy);
    };

    MiniEigen::Vector::Vector() {
    nRows = 0;
    nColumns = 0;
}
}



#endif
