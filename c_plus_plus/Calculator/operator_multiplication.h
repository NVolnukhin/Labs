#ifndef OPERATOR_MULTIPLICATION_H
#define OPERATOR_MULTIPLICATION_H

#include "operator.h"


class OperatorMultiplication : public Operator {
public:
    std::string getName() const override;
    OperatorPriority getPriority() override;
    Associativity getAssociativity() override;
    double evaluate(double a, double b) override;
};

#endif // OPERATOR_MULTIPLICATION_H
