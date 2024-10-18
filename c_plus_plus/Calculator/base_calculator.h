#ifndef BASE_CALCULATOR_H
#define BASE_CALCULATOR_H

#include <string>

class BaseCalculator {
public:
    virtual void calculate(std::string expression) = 0;
};

#endif // BASE_CALCULATOR_H
