#include "figures_composite.h"

bool CompositeFigures::validate() {
    throw std::exception();
}

double CompositeFigures::getPerimeter() {
    throw std::exception();
}

void CompositeFigures::printParameters() {
    throw std::exception();
}

void CompositeFigures::printPerimeter() {
    throw std::exception();
}

std::vector<std::shared_ptr<Figure>>& CompositeFigures::getFigures() {
    return figures;
}

size_t CompositeFigures::getSize() {
    return figures.size();
}

void CompositeFigures::addFigure(std::shared_ptr<Figure> figure) {
    figures.push_back(figure);
}

void CompositeFigures::deleteFigure(unsigned int i) {
    figures.erase(figures.begin() + i);
}
