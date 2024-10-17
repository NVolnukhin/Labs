#ifndef TRANSFORM_MATRIX_BUILDER_H
#define TRANSFORM_MATRIX_BUILDER_H
#include "transform_matrix.h"
#include "math.h"
#include "vector"

class TransformMatrixBuilder {
public:
    static TransformMatrix createRotationMatrixX(const float x);
    static TransformMatrix createRotationMatrixY(const float y);
    static TransformMatrix createRotationMatrixZ(const float z);
    static TransformMatrix createMoveMatrix(const float x, const float y, const float z);
    static TransformMatrix createScaleMatrix(const float x, const float y, const float z);
};


#endif // TRANSFORM_MATRIX_BUILDER_H
