#ifndef VERTEX_H
#define VERTEX_H
#include "point.h"
#include "scene_object.h"

class Vertex : public SceneObject {
public:
    Vertex(const Point& position);
    Point getPosition() const;
    void transform(const TransformMatrix& matrix) override;

private:
    Point _position;
};

#endif // VERTEX_H
