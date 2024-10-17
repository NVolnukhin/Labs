#include "qt_scene_drawer.h"
#include "QPainter"
#include <iostream>
#include "mainwindow.h"

QtSceneDrawer::QtSceneDrawer() {};


QtSceneDrawer::QtSceneDrawer(QPicture pixmap) {
    _pixmap = pixmap;
}


bool QtSceneDrawer::validateScene(std::shared_ptr<Scene> scene, const int height, const int width) {
    std::vector<Figure> figures = scene->getFigures();
    double x1, y1, x2, y2;
    bool ok = false;

    for (size_t i = 0; i < figures[0].getEdges()->size(); i++) {
        x1 = (figures[0].getEdges()->at(i).getBegin().getPosition().getX() + 2 * figures[0].getEdges()->at(i).getBegin().getPosition().getY() + figures[0].getEdges()->at(i).getBegin().getPosition().getZ()) / sqrt(6);
        y1 = (figures[0].getEdges()->at(i).getBegin().getPosition().getX() - figures[0].getEdges()->at(i).getBegin().getPosition().getZ()) / sqrt(2);

        x2 = (figures[0].getEdges()->at(i).getEnd().getPosition().getX() + 2 * figures[0].getEdges()->at(i).getEnd().getPosition().getY() + figures[0].getEdges()->at(i).getEnd().getPosition().getZ()) / sqrt(6);
        y2 = (figures[0].getEdges()->at(i).getEnd().getPosition().getX() - figures[0].getEdges()->at(i).getEnd().getPosition().getZ()) / sqrt(2);

        if ((x1 > -width / 4 && x1 < 3 * width / 4 && y1 > -height / 4 && y1 < 3 * height / 4) ||
            (x2 < -width / 4 && x2 > 3 * width / 4 && y2 < -height / 4 && y2 > 3 * height / 4)) {
            ok = true;
            break;
        }
    }

    return ok;
}


void QtSceneDrawer::drawScene(std::shared_ptr<Scene> scene) {
    if (scene == nullptr)
        throw "Scene was not drew";
    QPainter painter(&_pixmap);
    painter.translate(_pixmap.width() / 4, _pixmap.height() / 4);
    painter.fillRect(-_pixmap.width(), -_pixmap.height(), _pixmap.width() * 2, _pixmap.height() * 2, QBrush(QColor(Qt::GlobalColor::white)));
    painter.setPen(QColor(Qt::GlobalColor::black));

    std::vector<Figure> figures = scene->getFigures();
    float x1, x2, y1, y2;

    if (validateScene(scene, _pixmap.height(), _pixmap.width())) {
        for (size_t i = 0; i < figures[0].getEdges()->size(); i++) {
            x1 = (figures[0].getEdges()->at(i).getBegin().getPosition().getX() + 2 * figures[0].getEdges()->at(i).getBegin().getPosition().getY() + figures[0].getEdges()->at(i).getBegin().getPosition().getZ()) / sqrt(6);
            y1 = (figures[0].getEdges()->at(i).getBegin().getPosition().getX() - figures[0].getEdges()->at(i).getBegin().getPosition().getZ()) / sqrt(2);

            x2 = (figures[0].getEdges()->at(i).getEnd().getPosition().getX() + 2 * figures[0].getEdges()->at(i).getEnd().getPosition().getY() + figures[0].getEdges()->at(i).getEnd().getPosition().getZ()) / sqrt(6);
            y2 = (figures[0].getEdges()->at(i).getEnd().getPosition().getX() - figures[0].getEdges()->at(i).getEnd().getPosition().getZ()) / sqrt(2);

            painter.drawRect(x1 - 1, y1 - 1, 3, 3);

            painter.drawLine(x1, y1, x2, y2);
        }
    } else {
        throw "The picture cannot be rendered. To render, repeat the last steps with reverse values ​​or open the file again";
    }
}
