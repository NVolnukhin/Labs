#include "triangle.h"

bool Triangle::validate() {
    if (getPointsSize() != 3) {
        return false;
    }

    auto& pointVector = getPoints();

    auto& p1 = pointVector[0];
    auto& p2 = pointVector[1];
    auto& p3 = pointVector[2];

    return p1.x_ * (p2.y_ - p3.y_) + p2.x_ * (p3.y_ - p1.y_) + p3.x_ * (p1.y_ - p2.y_) != 0;
}

double Triangle::getPerimeter() {
    auto& pointVector = getPoints();
    auto& p1 = pointVector[0];
    auto& p2 = pointVector[1];
    auto& p3 = pointVector[2];

    double perimeter = Point::getLineLength(p1, p2) +
                       Point::getLineLength(p1, p3) +
                       Point::getLineLength(p2, p3);

    return perimeter;
}

void Triangle::printParameters() {
    auto& pointVector = getPoints();
    auto& p1 = pointVector[0];
    auto& p2 = pointVector[1];
    auto& p3 = pointVector[2];

    std::cout << "Triangle " << getName() << "\nPoint 1: ( " << p1.x_ << " , " << p1.y_ << " ) \nPoint 2: ( " << p2.x_ << " , " << p2.y_ << " ) \nPoint 3: ( " << p3.x_ << " , " << p3.y_ << " )\n" << std::endl;
}

void Triangle::printPerimeter() {
    std::cout << "Triangle with perimeter " << getPerimeter() << std::endl;
}
