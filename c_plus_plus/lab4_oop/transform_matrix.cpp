#include "transform_matrix.h"
#include <iostream>

TransformMatrix::TransformMatrix() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            _matrix[i][j] = 0;
        }
    }
}

TransformMatrix::TransformMatrix(const std::vector<std::vector<float>>& matrix) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            _matrix[i][j] = matrix[i][j];
        }
    }
}

TransformMatrix TransformMatrix::operator*(const TransformMatrix& new_matr) {
    TransformMatrix res;

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            for (int k = 0; k < MATRIX_SIZE; k++) {
                res._matrix[i][j] += _matrix[i][k] * new_matr._matrix[k][j];
            }
        }
    }

    return res;
}

Point TransformMatrix::transformPoint(Point& point) const {
    Point res;

    res.setX(_matrix[X][X] * point.getX() + _matrix[X][Y] * point.getY() + _matrix[X][Z] * point.getZ() + _matrix[X][ADDITIONAL]);
    res.setY(_matrix[Y][X] * point.getX() + _matrix[Y][Y] * point.getY() + _matrix[Y][Z] * point.getZ() + _matrix[Y][ADDITIONAL]);
    res.setZ(_matrix[Z][X] * point.getX() + _matrix[Z][Y] * point.getY() + _matrix[Z][Z] * point.getZ() + _matrix[Z][ADDITIONAL]);

    return res;
}


