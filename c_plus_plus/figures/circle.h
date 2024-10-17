#pragma once

#include "figures.h"

class Circle : public Figure {
public:
    bool validate() override;
    double getPerimeter() override;
    void printParameters() override;
    void printPerimeter() override;
    void getRadius();
private:
    double radius;
};

