#include "edge.h"

Edge::Edge(Vertex& begin, Vertex& end) : _begin(begin), _end(end) {}

Vertex Edge::getBegin() const {
    return _begin;
}

Vertex Edge::getEnd() const {
    return _end;
}
