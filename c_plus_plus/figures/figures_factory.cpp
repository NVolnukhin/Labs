#include "figures_factory.h"

#include "integer_input_manager.h"

std::shared_ptr<Circle> FigureFactory::createCircle() {
    Point center;
    std::shared_ptr<Circle> circle = std::make_shared<Circle>();

    circle->readName();

    std::cout << "Enter center of circle." << std::endl;
    center.getPoint();
    circle->addPoint(center);
    circle->getRadius();

    return circle;
}

std::shared_ptr<Rectangle> FigureFactory::createRectangle() {
    Point a, b;
    std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>();

    rectangle->readName();

    std::cout << "Enter left upper point coordinates." << std::endl;
    a.getPoint();
    std::cout << "Enter right down point coordinates." << std::endl;
    b.getPoint();
    rectangle->addPoint(a);
    rectangle->addPoint(b);

    return rectangle;
}

std::shared_ptr<Triangle> FigureFactory::createTriangle() {
    Point a, b, c;
    std::shared_ptr<Triangle> triangle = std::make_shared<Triangle>();

    triangle->readName();

    a.getPoint();
    triangle->addPoint(a);
    b.getPoint();
    triangle->addPoint(b);
    c.getPoint();
    triangle->addPoint(c);

    return triangle;
}

std::shared_ptr<Polygon> FigureFactory::createPolygon() {
    Point point;

    integerInputManager mng;
    unsigned int amount;
    unsigned int& refAmount {amount};
    std::shared_ptr<Polygon> polygon = std::make_shared<Polygon>();

    polygon->readName();

    std::cout << "How many points does a polygon have?" << std::endl;
    mng.GetPositiveInt(refAmount);

    for (unsigned int i = 0; i < amount; i++) {
        point.getPoint();
        polygon->addPoint(point);
    }

    std::cout << "Input is over" << std::endl;

    return polygon;
}
