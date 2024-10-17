#ifndef SCENE_DRAWER_BASE_H
#define SCENE_DRAWER_BASE_H
#include "scene.h"


class SceneDrawerBase {
public:
    virtual void drawScene(std::shared_ptr<Scene> scene) = 0;
    virtual ~SceneDrawerBase() {}
};

#endif // SCENE_DRAWER_BASE_H
