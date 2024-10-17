#pragma once

#include "abstract_figures_factory.h"



class FigureFactory : public AbstractFactory {
public:
    std::shared_ptr<Circle> createCircle() override;
    std::shared_ptr<Rectangle> createRectangle() override;
    std::shared_ptr<Triangle> createTriangle() override;
    std::shared_ptr<Polygon> createPolygon() override;
};



