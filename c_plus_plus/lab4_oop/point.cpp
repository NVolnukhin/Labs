#include "point.h"

Point::Point() : _x(0), _y(0), _z(0) {}

Point::Point(float x, float y, float z) : _x(x), _y(y), _z(z) {}

double Point::getX() {
    return _x;
}

double Point::getY() {
    return _y;
}

double Point::getZ() {
    return _z;
}

void Point::setX(double x) {
    _x = x;
}

void Point::setY(double y) {
    _y = y;
}

void Point::setZ(double z) {
    _z = z;
}
