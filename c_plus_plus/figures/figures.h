#pragma once

#include "points.h"

class Figure {
public:
    virtual bool validate() = 0;
    virtual double getPerimeter() = 0;
    virtual void printParameters() = 0;
    virtual void printPerimeter() = 0;

    void addPoint(Point);
    size_t getPointsSize();
    void readName();
    std::string& getName();
    std::vector<Point>& getPoints();
private:
    std::string name;
    std::vector<Point> points;

};
