#ifndef FUNCTION_SIN_H
#define FUNCTION_SIN_H

#include "function.h"


class FunctionSin : public Function {
public:
    double evaluate(std::vector<double>& args) override;
    std::string getName() override;
};

#endif // FUNCTION_SIN_H
