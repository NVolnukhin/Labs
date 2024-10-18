#include "function_sin.h"

double FunctionSin::evaluate(std::vector<double>& args) {
    return std::sin(args[0]);
}


std::string FunctionSin::getName() {
    return "sin";
}
