#ifndef OPERATOR_PLUS_H
#define OPERATOR_PLUS_H

#include "operator.h"


class OperatorPlus : public Operator {
public:
    std::string getName() const override;
    OperatorPriority getPriority() override;
    Associativity getAssociativity() override;
    double evaluate(double a, double b) override;
};

#endif // OPERATOR_PLUS_H
