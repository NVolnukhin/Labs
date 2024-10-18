#include "function_cos.h"

double FunctionCos::evaluate(std::vector<double>& args) {
    return std::cos(args[0]);
}


std::string FunctionCos::getName() {
    return "cos";
}
