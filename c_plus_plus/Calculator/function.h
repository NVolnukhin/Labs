#ifndef FUNCTION_H
#define FUNCTION_H

#include <cstddef>
#include <vector>
#include <string>


class Function {
public:
    Function(const std::string& name, size_t argc, double (*func)(std::vector<double>&));
    Function() {}

    size_t getArgc();
    virtual double evaluate(std::vector<double>& args);
    virtual std::string getName();

    virtual ~Function() {}

private:
    size_t _argc = 1;
    const std::string _name;
    double (*_func)(std::vector<double>&);
};

#endif // FUNCTION_H
