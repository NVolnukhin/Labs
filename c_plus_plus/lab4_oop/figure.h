#ifndef FIGURE_H
#define FIGURE_H


#include "vertex.h"
#include "edge.h"
#include "transform_matrix.h"
#include "scene_object.h"
#include "vector"

class Figure : public SceneObject {
public:
    Figure() = default;
    Figure(std::vector<Vertex>* vertices, std::vector<Edge>* edges);
    std::vector<Vertex>* getVertices() const;
    std::vector<Edge>* getEdges() const;
    void transform(const TransformMatrix& matrix) override;

private:
    std::vector<Vertex>* _vertices;
    std::vector<Edge>* _edges;
};

#endif // FIGURE_H
