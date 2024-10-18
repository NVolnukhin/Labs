#include "operator_plus.h"

std::string OperatorPlus::getName() const {
    return "+";
}


Operator::OperatorPriority OperatorPlus::getPriority() {
    return Operator::OperatorPriority::LOW;
}


Operator::Associativity OperatorPlus::getAssociativity() {
    return Operator::Associativity::LEFT;
}


double OperatorPlus::evaluate(double a, double b) {
    return a + b;
}
