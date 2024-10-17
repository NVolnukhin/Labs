#include "circle.h"
#include "float_input_manager.h"



bool Circle::validate() {
    if (getPointsSize() != 1) {
        return false;
    }
    return radius > 0;
}


double Circle::getPerimeter() {
    return 2 * M_PI * radius;
}


void Circle::printParameters() {
    auto& pointVector = getPoints();
    auto& center = pointVector[0];
    std::cout << "Circle " << getName() << "\nCenter: ( " << center.x_ << " , " << center.y_ << " ) \nRadius: " << radius << "\n" << std::endl;
}


void Circle::printPerimeter() {
    std::cout << "Circle with perimeter " << getPerimeter() << std::endl;
}


void Circle::getRadius() {
    floatInputManager mng;
    std::cout << "Enter radius of circle: ";
    double& refRadius {radius};
    mng.GetPositiveDouble(refRadius);
}
