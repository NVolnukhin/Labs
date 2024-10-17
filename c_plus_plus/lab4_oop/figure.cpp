#include "figure.h"

Figure::Figure(std::vector<Vertex>* vertices, std::vector<Edge>* edges) : _vertices(vertices), _edges(edges) {}


std::vector<Vertex>* Figure::getVertices() const {
    return _vertices;
}

std::vector<Edge>* Figure::getEdges() const {
    return _edges;
}

void Figure::transform(const TransformMatrix& matrix) {
    for(size_t i = 0; i < _vertices->size(); i++) {
        _vertices->at(i).transform(matrix);
    }
}
