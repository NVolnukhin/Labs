#include "polygon.h"
#include "points.h"

bool Polygon::validate() {
    if (getPointsSize() < 3) {
        std::cout << "Polygon should have 3 or more vertexes" << std::endl;
        return false;
    }
    auto pointVector = getPoints();

    //and now checking if polygon is convex
    for (int i = 0; i < (int)getPointsSize(); i++) {
        Point A = pointVector[i == 0 ? (int)getPointsSize() - 1 : i - 1];
        Point B = pointVector[i];
        Point C = pointVector[i == (int)getPointsSize() - 1 ? 0 : i + 1];

        double sinalpha = ((C.y_ -A.y_) * (B.x_ - A.x_) - (B.y_ - A.y_) * (C.x_ - A.x_)) /
                          (sqrt((B.x_ - A.y_) * (B.x_ - A.x_)) *
                           sqrt((C.y_ - A.y_) * (C.x_ - A.x_)));

        if (sinalpha > 0) {
            std::cout << "Polygon is not convex" << std::endl;
            return false;
        }
    }

    return true;
}

double Polygon::getPerimeter() {
    double perimeter = 0;
    auto pointVector = getPoints();

    for (int i = 0; i < (int)getPointsSize() - 1; i++) {
        perimeter += Point::getLineLength(pointVector[i], pointVector[i + 1]);
    }
    perimeter += Point::getLineLength(pointVector[0], pointVector[(int)getPointsSize() - 1]);

    return perimeter;
}

void PrintPoint(Point& point) {
    std::cout << " ( " << point.x_ << " , " << point.y_ << " ) ";
};

void Polygon::printParameters() {
    std::cout << "Polygon " << getName() << std::endl;

    auto& pointVector = getPoints();
    for (int i = 0; i < (int)getPointsSize(); i++) {
        std::cout << "Point " << i + 1;
        pointVector[i].printPoint();
        std::cout << std::endl;
    }
}




void Polygon::printPerimeter() {
    std::cout << "Polygon with perimeter " << getPerimeter() << std::endl;
}
