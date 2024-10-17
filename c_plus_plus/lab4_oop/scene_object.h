#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H
#include "transform_matrix.h"

class SceneObject {
public:
    virtual void transform(const TransformMatrix& matrix) = 0;
    virtual ~SceneObject() {}
};

#endif // SCENE_OBJECT_H
