#pragma once

#include "figures.h"

class CompositeFigures: public Figure {
public:
    bool validate() override;
    double getPerimeter() override;
    void printParameters() override;
    void printPerimeter() override;

    std::vector<std::shared_ptr<Figure>>& getFigures();
    size_t getSize();
    void addFigure(std::shared_ptr<Figure> figure);
    void deleteFigure(unsigned int i);
private:
    std::vector<std::shared_ptr<Figure>> figures;
};
