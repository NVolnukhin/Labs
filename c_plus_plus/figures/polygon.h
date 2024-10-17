#pragma once

#include "figures.h"

class Polygon : public Figure {
public:
    bool validate() override;
    double getPerimeter() override;
    void printParameters() override;
    void printPerimeter() override;
};
