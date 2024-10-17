#include "points.h"

void Point::printPoint() {
    std::cout << " ( " << x_ << " , " << y_ << " ) ";
};

void Point::getPoint() {
    std::cout << "Input coordinates (X; Y) : ";
    int countOfSuccessreaded = std::scanf("%lf;%lf", &x_, &y_);

    while (countOfSuccessreaded != ARG_COUNT) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "You entered an incorrect value. Enter float coordinates (X; Y): " << std::endl;
        countOfSuccessreaded = std::scanf("%lf; %lf", &x_, &y_);
    }
};

double Point::getPolarAngle(Point& point) {
    return atan2(point.y_, point.x_);
}

double Point::getLineLength(Point& point1, Point& point2) {
    return sqrt((pow(point2.x_ - point1.x_, 2)) + pow(point2.y_ - point1.y_, 2));
}
