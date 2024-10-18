#include "function_ctg.h"

double FunctionCtg::evaluate(std::vector<double>& args) {
    return 1 / std::tan(args[0]);
}

std::string FunctionCtg::getName() {
    return "ctg";
}
