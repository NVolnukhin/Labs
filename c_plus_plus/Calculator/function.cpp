#include "function.h"


Function::Function(const std::string& name, size_t argc, double (*func)(std::vector<double>&)) :
    _argc(argc), _name(name), _func(func) {};


size_t Function::getArgc() {
    return _argc;
}


double Function::evaluate(std::vector<double>& args) {
    return _func(args);
}


std::string Function::getName() {
    return _name;
}
