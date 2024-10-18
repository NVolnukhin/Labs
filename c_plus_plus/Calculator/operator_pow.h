#ifndef OPERATOR_POW_H
#define OPERATOR_POW_H

#include "operator.h"


class OperatorPow : public Operator {
public:
    std::string getName() const override;
    OperatorPriority getPriority() override;
    Associativity getAssociativity() override;
    double evaluate(double a, double b) override;
};

#endif // OPERATOR_POW_H
