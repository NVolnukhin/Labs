#include "operator_pow.h"

std::string OperatorPow::getName() const {
    return "^";
}


Operator::OperatorPriority OperatorPow::getPriority() {
    return Operator::OperatorPriority::HIGH;
}


Operator::Associativity OperatorPow::getAssociativity() {
    return Operator::Associativity::RIGHT;
}


double OperatorPow::evaluate(double a, double b) {
    return std::pow(a, b);
}
