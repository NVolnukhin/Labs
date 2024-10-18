#include "function_tg.h"

double FunctionTg::evaluate(std::vector<double>& args) {
    return std::tan(args[0]);
}


std::string FunctionTg::getName() {
    return "tg";
}
