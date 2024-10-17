#pragma once

#include "figures.h"

class Rectangle : public Figure {
public:
    bool validate() override;
    double getPerimeter() override;
    void printParameters() override;
    void printPerimeter() override;
};
