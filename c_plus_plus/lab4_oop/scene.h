#ifndef SCENE_H
#define SCENE_H

#include "figure.h"
#include "transform_matrix.h"


class Scene {
public:
    Scene() = default;
    Scene(std::vector<Figure>& figure);
    std::vector<Figure> getFigures() const;
    void transformFigures(TransformMatrix& matrix);

private:
    std::vector<Figure> _figures;
};

#endif // SCENE_H
