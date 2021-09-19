# MiniEigen
A fast C++ (non-template) library for Linear Algebra. Inspired by TuxFamily's Eigen. If you're interested in using MiniEigen, jump to the [Quickstart Guide](#quickstart).

# Motivation
While working on a project with Eigen, I noticed that compilation times were pretty long when dealing with heavy pieces of data. Eigen was able to handle everything I threw at it, which I found quite interesting. I wanted to make a faster version of Eigen, which would definitely involve removing a lot of the abstractions Eigen has built-in. Also, this would be a chance for me to put my knowledge of some C++11 features to the test. (As I'm writing this, some of the features I explain may not be in the repository already. This is because there are a lot of "checks" that need to happen in order for computations to produce bug-free results. Most features work well when a given matrix is square and are in RREF, though.)

# Depencencies
MiniEigen is built completely on C++'s standard. There are no dependencies.


# Installation
Clone this repository into your project folder and include the matrix (or vector) header file: `#include "Matrix.h"`

# Quickstart

To construct an empty matrix of size 3x3:

`MiniEigen::Matrix m = MiniEigen::Matrix(3,3);`

MiniEigen uses linear-based indexing so a `std::vector<double>` can be converted into a `MiniEigen::Matrix`.


