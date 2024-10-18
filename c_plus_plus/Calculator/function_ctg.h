#ifndef FUNCTION_CTG_H
#define FUNCTION_CTG_H

#include "function.h"


class FunctionCtg : public Function {
public:
    double evaluate(std::vector<double>& args) override;
    std::string getName() override;
};

#endif // FUNCTION_CTG_H
