#ifndef EVALUATOR_H
#define EVALUATOR_H


#include "token.h"
#include <memory>

using namespace TokenSpace;

class Evaluator {
public:
    double evaluate(std::shared_ptr<std::vector<Token>> rpnExpression);
};

#endif // EVALUATOR_H
