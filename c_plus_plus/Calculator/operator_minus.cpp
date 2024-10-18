#include "operator_minus.h"

std::string OperatorMinus::getName() const {
    return "-";
}


Operator::OperatorPriority OperatorMinus::getPriority() {
    return Operator::OperatorPriority::LOW;
}


Operator::Associativity OperatorMinus::getAssociativity() {
    return Operator::Associativity::LEFT;
}


double OperatorMinus::evaluate(double a, double b) {
    return a - b;
}
