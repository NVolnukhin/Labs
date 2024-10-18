#include "function_sqrt.h"

double FunctionSqrt::evaluate(std::vector<double>& args) {
    return std::sqrt(args[0]);
}


std::string FunctionSqrt::getName() {
    return "sqrt";
}
