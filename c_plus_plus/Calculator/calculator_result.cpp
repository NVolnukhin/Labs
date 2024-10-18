#include "calculator_result.h"

std::string CalculatorResult::getAns() {
    return _status ? _result : "err";
}


bool CalculatorResult::getStatus() {
    return true;
}
