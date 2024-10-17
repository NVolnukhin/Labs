#ifndef QT_SCENE_DRAWER_H
#define QT_SCENE_DRAWER_H
#include "scene_drawer_base.h"
#include <QObject>
#include <QPixmap>
#include <QPicture>

class QtSceneDrawer : public SceneDrawerBase {
public:
    QtSceneDrawer();
    QtSceneDrawer(QPicture pixmap);
    void drawScene(std::shared_ptr<Scene> scene) override;

private:
    static bool validateScene(std::shared_ptr<Scene> scene, const int height, const int width);
    QPicture _pixmap;
};

#endif // QT_SCENE_DRAWER_H
