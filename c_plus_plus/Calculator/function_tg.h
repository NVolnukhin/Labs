#ifndef FUNCTION_TG_H
#define FUNCTION_TG_H

#include "function.h"


class FunctionTg : public Function {
public:
    double evaluate(std::vector<double>& args) override;
    std::string getName() override;
};

#endif // FUNCTION_TG_H
