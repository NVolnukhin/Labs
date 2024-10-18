#include "operator_multiplication.h"

std::string OperatorMultiplication::getName() const {
    return "*";
}


Operator::OperatorPriority OperatorMultiplication::getPriority() {
    return Operator::OperatorPriority::MID;
}


Operator::Associativity OperatorMultiplication::getAssociativity() {
    return Operator::Associativity::LEFT;
}


double OperatorMultiplication::evaluate(double a, double b) {
    return a * b;
}
