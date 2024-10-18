#include "simple_calculator.h"
#include "tokenizer.h"
#include "evaluator.h"

void SimpleCalculator::calculate(std::string expression) {
    double answer = 0;
    _status = true;
    auto tokenizer = std::make_shared<Tokenizer>();
    auto evaluator = std::make_shared<Evaluator>();

    try {
        auto tokens = tokenizer->tokenize(expression);
        auto tokensRPN = tokenizer->convertToRpn(tokens);
        answer = evaluator->evaluate(tokensRPN);

        if (!std::isfinite(answer)) {
            _status = false;
        }

        std::cout << answer << std::endl;
    } catch (const SyntaxError& ex) {
        std::cout << ex.what() << std::endl;
        _status = false;
    } catch (const InvalidInput& ex) {
        std::cout << ex.what() << std::endl;
        _status = false;
    }

    _result = std::to_string(answer);
}
