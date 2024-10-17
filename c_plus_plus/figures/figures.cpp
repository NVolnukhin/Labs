#include "figures.h"

void Figure::readName() {
    std::cout << "\nInput name of figure: ";
    std::fflush(stdin);
    std::getline(std::cin, name);
}

std::string& Figure::getName() {
    return name;
}

void Figure::addPoint(Point n) {
    points.push_back(n);
}

size_t Figure::getPointsSize() {
    return points.size();
}

std::vector<Point>& Figure::getPoints() {
    return points;
}
