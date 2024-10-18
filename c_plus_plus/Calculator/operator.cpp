#include "operator.h"


double Operator::evaluate(double a, double b) {
    return _func(a, b);
}

std::string Operator::getName() const {
    return _name;
}


Operator::OperatorPriority Operator::getPriority() {
    return _priority;
}


Operator::Associativity Operator::getAssociativity() {
    return _assoc;
}
