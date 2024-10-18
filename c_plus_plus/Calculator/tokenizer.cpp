#include "tokenizer.h"

std::string Tokenizer::getNumber(std::string::const_iterator& it, std::string::const_iterator end) {
    std::string value;
    bool dotExists = false;

    while (it != end && (isdigit(*it) || *it == '.')) {
        value += *it;
        if (*it == '.') {
            if (dotExists) {
                throw InvalidInput("Invalid number in input");
            }
            else {
                dotExists = true;
            }
        }
        it++;
    }

    if (value.empty()) {
        throw InvalidInput("Excepted a number, but nothing found");
    }

    return value;
}

std::string Tokenizer::getName(std::string::const_iterator& it, std::string::const_iterator end) {
    std::string value;

    while (it != end && isalpha(*it)) {
        value += *it;
        it++;
    }

    if (value.empty()) {
        throw InvalidInput("Excepted a name, nothing found");
    }

    return value;
}

std::shared_ptr<std::vector<Token>> Tokenizer::tokenize(const std::string& expression) {
    if (expression == "") {
        throw InvalidInput("There's no expression");
    }

    std::cout << expression << std::endl;
    std::vector<Token> tokens;

    OperatorMap::const_iterator operatorIt;
    FunctionMap::const_iterator functionIt;
    auto it = expression.cbegin();

    MinusState minusState = MinusState::UNARY;
    PlusState plusState = PlusState::UNARY;

    while (it != expression.cend()) {
        if (whitespaces.find(*it) != whitespaces.cend()) { }
        else if (isdigit(*it) || *it == '.') {  // handle number
            if (!tokens.empty() && (tokens.back().type != Token::Type::OPERATOR &&
                                    tokens.back().type != Token::Type::LEFTPARENTHESES)) {
                std::cout << tokens.size() << std::endl;
                throw SyntaxError("Missing '(' or ',' or operator  before number here");
            }

            std::string numberStr;

            try {
                numberStr = getNumber(it, expression.cend());
            } catch (InvalidInput& ex) {
                throw ex;
            }

            double number = 0;

            try {
                number = std::stod(numberStr);
            } catch (...) {
                throw SyntaxError("Invalid expression");
            }

            tokens.emplace(tokens.end(), number);
            minusState = MinusState::BINARY;
            plusState = PlusState::BINARY;
            continue;
        } else if ((operatorIt = operators.find(*it)) != operators.cend()) {
            std::shared_ptr< Operator > oper = operatorIt->second;
            if (minusState == MinusState::UNARY && oper->getName() == "-") {
                tokens.emplace(tokens.end(), 0.0);
            } else if (plusState == PlusState::UNARY && oper->getName() == "+") {
                tokens.emplace(tokens.end(), 0.0);
            } else {  // check binary operators
                if (!tokens.empty() && (tokens.back().type != Token::Type::NUMBER &&
                                        tokens.back().type != Token::Type::RIGHTPARENTHESES)) {
                    throw SyntaxError("Missing ')' or number before binary operator");
                }
            }

            tokens.emplace(tokens.end(), oper);
        } else if (*it == '(') {
            if (!tokens.empty() && (tokens.back().type != Token::Type::OPERATOR &&
                                    tokens.back().type != Token::Type::FUNCTION &&
                                    tokens.back().type != Token::Type::LEFTPARENTHESES)) {
                throw SyntaxError("Missing '(' or ',' or operator or function before '('");
            }

            tokens.emplace(tokens.end(), *it);
            minusState = MinusState::UNARY;
            plusState = PlusState::UNARY;
        } else if (*it == ')') {
            if (!tokens.empty() && (tokens.back().type != Token::Type::NUMBER &&
                                    tokens.back().type != Token::Type::RIGHTPARENTHESES)) {
                throw SyntaxError("Missing ')' or number before ')'");
            }

            tokens.emplace(tokens.end(), *it);
            minusState = MinusState::BINARY;
            plusState = PlusState::BINARY;
        } else if (isalpha(*it)) {  // handle function name
            if (!tokens.empty() && (tokens.back().type != Token::Type::OPERATOR &&
                                    tokens.back().type != Token::Type::LEFTPARENTHESES)) {
                throw SyntaxError("Missing operator before function");
            }

            std::string name;

            try {
                name = getName(it, expression.cend());
            } catch (InvalidInput& ex) {
                std::rethrow_exception(std::make_exception_ptr(ex));
            }

            functionIt = functions.find(name);
            if (functionIt != functions.cend()) {
                tokens.emplace(tokens.end(), functionIt->second);
            } else {
                throw InvalidInput("Function not exists: " + name);
            }

            plusState = PlusState::BINARY;
            minusState = MinusState::BINARY;

            continue;
        } else {
            throw InvalidInput("Invalid char: " + std::string(1, *it));
        }

        ++it;
    }

    return std::make_shared<std::vector<Token>>(tokens);
}

std::shared_ptr< std::vector<Token>> Tokenizer::convertToRpn(std::shared_ptr<std::vector<Token>> input) {
    std::stack<Token> stack;
    std::vector<Token> output;

    for (auto token : *input) {
        if (token.getType() == Token::Type::NUMBER) {
            output.push_back(token);
        }
        else if (token.getType() == Token::Type::FUNCTION) {
            stack.push(token);
        } else if (token.getType() == Token::Type::OPERATOR) {
            Operator* cur = token.getValue().oper;
            while (!stack.empty()) {
                Token top = stack.top();
                if (top.getType() == Token::Type::OPERATOR) {
                    Operator* op = top.getValue().oper;
                    if (op->getPriority() > cur->getPriority() ||
                        (op->getPriority() == cur->getPriority() && cur->getAssociativity() == Operator::Associativity::LEFT)) {
                        output.push_back(top);
                        stack.pop();
                    } else {
                        break;
                    }
                } else if(top.getType() == Token::Type::FUNCTION) {
                    output.push_back(top);
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push(token);
        } else if (token.getType() == Token::Type::LEFTPARENTHESES) {
            stack.push(token);
        } else if (token.getType() == Token::Type::RIGHTPARENTHESES) {
            bool paranCheck = false;
            while (!stack.empty()) {
                Token top = stack.top();
                stack.pop();
                if (top.getType() == Token::Type::LEFTPARENTHESES)
                {
                    paranCheck = true;
                    break;
                }
                output.push_back(top);
            }
            if (!paranCheck) {
                throw SyntaxError("Missing left brace '(' in expression");
            }
        }
    }

    while (!stack.empty()) {
        Token top = stack.top();
        stack.pop();
        if (top.getType() == Token::Type::LEFTPARENTHESES) {
            throw SyntaxError("Missing right brace ')' in expression");
        }
        output.push_back(top);
    }

    return std::make_shared<std::vector<Token>>(output);
}
