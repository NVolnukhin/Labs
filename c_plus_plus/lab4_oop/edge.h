#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"

class Edge {
public:
    Edge(Vertex& begin, Vertex& end);
    Vertex getBegin() const;
    Vertex getEnd() const;

private:
    Vertex& _begin;
    Vertex& _end;
};


#endif // EDGE_H
