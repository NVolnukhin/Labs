#include "operator_division.h"

std::string OperatorDivision::getName() const {
    return "/";
}


Operator::OperatorPriority OperatorDivision::getPriority() {
    return Operator::OperatorPriority::MID;
}


Operator::Associativity OperatorDivision::getAssociativity() {
    return Operator::Associativity::LEFT;
}


double OperatorDivision::evaluate(double a, double b) {
    return a / b;
}
