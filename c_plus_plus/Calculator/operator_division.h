#ifndef OPERATOR_DIVISION_H
#define OPERATOR_DIVISION_H

#include "operator.h"


class OperatorDivision : public Operator {
public:
    std::string getName() const override;
    OperatorPriority getPriority() override;
    Associativity getAssociativity() override;
    double evaluate(double a, double b) override;
};


#endif // OPERATOR_DIVISION_H
