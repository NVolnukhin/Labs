#pragma once
#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "polygon.h"

class AbstractFactory {
public:
    virtual std::shared_ptr<Circle> createCircle() = 0;
    virtual std::shared_ptr<Rectangle> createRectangle() = 0;
    virtual std::shared_ptr<Triangle> createTriangle() = 0;
    virtual std::shared_ptr<Polygon> createPolygon() = 0;
};
