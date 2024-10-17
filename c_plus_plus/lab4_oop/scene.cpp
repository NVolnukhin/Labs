#include "scene.h"

Scene::Scene(std::vector<Figure>& figure) : _figures(figure) {}

std::vector<Figure> Scene::getFigures() const {
    return _figures;
}

void Scene::transformFigures(TransformMatrix& matrix) {
    for (Figure& figure : _figures) {
        figure.transform(matrix);
    }
}
