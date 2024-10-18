#ifndef CALCULATOR_RESULT_H
#define CALCULATOR_RESULT_H

#include <string>

class CalculatorResult {
public:
    CalculatorResult() : _result("Empty"), _status(false) {}
    CalculatorResult(std::string& result, bool status) : _result(result), _status(status) {}
    std::string getAns();
    bool getStatus();

private:
    std::string _result;
    bool _status;
};

#endif // CALCULATOR_RESULT_H
