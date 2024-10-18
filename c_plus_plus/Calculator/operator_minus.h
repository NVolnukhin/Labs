#ifndef OPERATOR_MINUS_H
#define OPERATOR_MINUS_H

#include "operator.h"


class OperatorMinus : public Operator {
public:
    std::string getName() const override;
    OperatorPriority getPriority() override;
    Associativity getAssociativity() override;
    double evaluate(double a, double b) override;
};

#endif // OPERATOR_MINUS_H
