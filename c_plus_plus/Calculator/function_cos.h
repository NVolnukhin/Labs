#ifndef FUNCTION_COS_H
#define FUNCTION_COS_H

#include "function.h"


class FunctionCos : public Function {
public:
    double evaluate(std::vector<double>& args) override;
    std::string getName() override;
};

#endif // FUNCTION_COS_H
