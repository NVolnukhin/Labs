#include "evaluator.h"
#include "token.h"
#include <stack>
#include <iostream>

double Evaluator::evaluate(std::shared_ptr<std::vector<Token>> rpnExpression) {
    std::stack<double> stack;

    for (auto token : *rpnExpression) {
        if (token.getType() == Token::Type::NUMBER) {
            stack.push(token.getValue().number);
        } else if (token.getType() == Token::Type::OPERATOR) {
            if (stack.size() < 2) {
                throw SyntaxError("Not enought operands");
            }

            double b = stack.top();
            stack.pop();

            double a = stack.top();
            stack.pop();

            stack.push(token.getValue().oper->evaluate(a, b));
        } else if (token.getType() == Token::Type::FUNCTION) {
            if (stack.size() < 1) {
                throw SyntaxError("Not enough operands");
            }

            double a = stack.top();
            stack.pop();

            std::vector<double> argv;
            argv.push_back(a);

            stack.push(token.getValue().func->evaluate(argv));
        } else {
            throw SyntaxError("Not enought operands");
        }
    }

    if (stack.size() > 1) {
        throw SyntaxError("....");
    }

    return stack.top();
}
