#include "transform_matrix_builder.h"

TransformMatrix TransformMatrixBuilder::createRotationMatrixX(const float x) {
    float rad_x = M_PI / 180 * x;

    std::vector <std::vector<float>> matrix = {
                                              {1, 0, 0, 0},
                                              {0, cos(rad_x), -sin(rad_x), 0},
                                              {0, sin(rad_x), cos(rad_x), 0},
                                              {0, 0, 0, 1},
                                              };
    TransformMatrix res = TransformMatrix(matrix);

    return res;
}

TransformMatrix TransformMatrixBuilder::createRotationMatrixY(const float y) {
    float rad_y = M_PI / 180 * y;

    std::vector <std::vector<float>> matrix = {
                                              {cos(rad_y), 0, sin(rad_y), 0},
                                              {0, 1, 0, 0},
                                              {-sin(rad_y), 0, cos(rad_y), 0},
                                              {0, 0, 0, 1},
                                              };
    TransformMatrix res = TransformMatrix(matrix);

    return res;
}

TransformMatrix TransformMatrixBuilder::createRotationMatrixZ(const float z) {
    float rad_z = M_PI / 180 * z;

    std::vector <std::vector<float>> matrix = {
                                              {cos(rad_z), -sin(rad_z), 0, 0},
                                              {sin(rad_z), cos(rad_z), 0, 0},
                                              {0, 0, 1, 0},
                                              {0, 0, 0, 1},
                                              };
    TransformMatrix res = TransformMatrix(matrix);

    return res;
}

TransformMatrix TransformMatrixBuilder::createMoveMatrix(const float x, const float y, const float z) {
    std::vector <std::vector<float>> moveMatrix = {
                                                  {1, 0, 0, x},
                                                  {0, 1, 0, y},
                                                  {0, 0, 1, z},
                                                  {0, 0, 0, 1},
                                                  };
    TransformMatrix res = TransformMatrix(moveMatrix);

    return res;
}

TransformMatrix TransformMatrixBuilder::createScaleMatrix(const float x, const float y, const float z) {
    std::vector <std::vector<float>> scaleMatrix = {
                                                   {x/100, 0, 0, 0},
                                                   {0, y/100, 0, 0},
                                                   {0, 0, z/100, 0},
                                                   {0, 0, 0, 1},
                                                   };
    TransformMatrix res = TransformMatrix(scaleMatrix);

    return res;
}
