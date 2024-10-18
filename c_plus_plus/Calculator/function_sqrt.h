#ifndef FUNCTION_SQRT_H
#define FUNCTION_SQRT_H

#include "function.h"


class FunctionSqrt : public Function {
public:
    double evaluate(std::vector<double>& args) override;
    std::string getName() override;
};

#endif // FUNCTION_SQRT_H
