#include "vertex.h"

Vertex::Vertex(const Point& position) : _position(position) {}

void Vertex::transform(const TransformMatrix& matrix) {
    Point tempPoint;
    tempPoint = matrix.transformPoint(_position);
    _position = tempPoint;
}

Point Vertex::getPosition() const {
    return _position;
}
