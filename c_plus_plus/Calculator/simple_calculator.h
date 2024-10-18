#ifndef SIMPLE_CALCULATOR_H
#define SIMPLE_CALCULATOR_H

#include "base_calculator.h"
#include "calculator_result.h"
#include <iostream>

class SimpleCalculator : public BaseCalculator {
public:
    void calculate(std::string expression) override;
    CalculatorResult getResult() { return CalculatorResult(_result, _status); };

private:
    std::string _result;
    bool _status;
};

#endif // SIMPLE_CALCULATOR_H
