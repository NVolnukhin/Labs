#ifndef TOKEN_H
#define TOKEN_H
#define ONE 1

#include <stdlib.h>
#include "property.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

#include "operator.h"
#include "operator_plus.h"
#include "operator_minus.h"
#include "operator_multiplication.h"
#include "operator_division.h"
#include "operator_pow.h"

#include "function.h"
#include "function_sin.h"
#include "function_cos.h"
#include "function_tg.h"
#include "function_ctg.h"
#include "function_sqrt.h"



class InvalidInput : public std::invalid_argument {
    using std::invalid_argument::invalid_argument;
};

class SyntaxError : public std::invalid_argument {
    using std::invalid_argument::invalid_argument;
};

namespace TokenSpace {

enum class MinusState {
    UNARY,
    BINARY,
};

enum class PlusState {
    UNARY,
    BINARY
};

class Token {
public:
    enum class Type {
        NUMBER,
        OPERATOR,
        FUNCTION,
        LEFTPARENTHESES,
        RIGHTPARENTHESES,
    };

private:
    Type _type = Type::NUMBER;

    union UValue {
        double number = 0;
        Operator* oper;
        Function* func;
    } _value;

public:
    Token();
    Token(Type type);
    Token(double number);
    Token(std::shared_ptr<Operator> oper);
    Token(std::shared_ptr<Function> func);
    Token(char parenthesis);

    UValue getValue() { return _value; };

    Type getType() const;
    void setType(const Type &type);
    Property<Token, Type> type;
};

using OperatorMap = typename std::unordered_map<char, std::shared_ptr<Operator>>;
using FunctionMap = typename std::unordered_map<std::string, std::shared_ptr<Function>>;

const OperatorMap operators ({
    {'+', std::make_shared<OperatorPlus>()},
    {'-', std::make_shared<OperatorMinus>()},
    {'*', std::make_shared<OperatorMultiplication>()},
    {'/', std::make_shared<OperatorDivision>()},
    {'^', std::make_shared<OperatorPow>()},
});

const FunctionMap functions ({
    {"sin", std::make_shared<FunctionSin>()},
    {"cos", std::make_shared<FunctionCos>()},
    {"tg", std::make_shared<FunctionTg>()},
    {"ctg", std::make_shared<FunctionCtg>()},
    {"sqrt", std::make_shared<FunctionSqrt>()},
});

const std::unordered_set<char> whitespaces ({' ', '\n', '\t'});

}

#endif // TOKEN_H
