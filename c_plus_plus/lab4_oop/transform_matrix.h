#ifndef TRANSFORM_MATRIX_H
#define TRANSFORM_MATRIX_H

#include "point.h"
#include "vector"
#define MATRIX_SIZE 4

class TransformMatrix {
public:
    enum Index {
        X = 0,
        Y,
        Z,
        ADDITIONAL
    };

    TransformMatrix();
    TransformMatrix(const std::vector<std::vector<float>>& matrix);
    TransformMatrix operator*(const TransformMatrix& new_matr);
    Point transformPoint(Point& point) const;

private:
    float _matrix[MATRIX_SIZE][MATRIX_SIZE];
};

#endif // TRANSFORM_MATRIX_H
