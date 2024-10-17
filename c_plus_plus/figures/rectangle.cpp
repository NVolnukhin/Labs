#include "rectangle.h"

bool Rectangle::validate() {
    if (getPointsSize() != 2) {
        return false;
    }
    auto& pointVector = getPoints();
    auto& p1 = pointVector[0];
    auto& p2 = pointVector[1];

    return p1.x_ < p2.x_ && p1.y_ > p2.y_;
}

double Rectangle::getPerimeter() {
    auto& pointVector = getPoints();
    auto& p1 = pointVector[0];
    auto& p2 = pointVector[1];
    return (abs(p2.x_ - p1.x_) + abs(p2.y_ - p1.y_)) * 2;
}

void Rectangle::printParameters() {
    auto& pointVector = getPoints();
    auto& p1 = pointVector[0];
    auto& p2 = pointVector[1];

    std::cout << "Rectangle " << getName() << "\nPoint 1: ( " << p1.x_ << " , " << p1.y_ << " ) \nPoint 2: ( " << p2.x_ << " , " << p2.y_ << " ) \n" << std::endl;
}

void Rectangle::printPerimeter() {
    std::cout << "Rectangle with perimeter " << getPerimeter() << std::endl;
}

