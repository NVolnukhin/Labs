#include "token.h"


using namespace TokenSpace;

Token::Type Token::getType() const {
    return _type;
}


void Token::setType(const Type& type) {
    _type = type;
}


Token::Token() {
    _type = Type::NUMBER;
    type.init(this, &Token::getType, &Token::setType);
}


Token::Token(Type type) : Token() {
    _type = type;
}


Token::Token(double number) : Token() {
    _value.number = number;
    _type = Type::NUMBER;
}


Token::Token(std::shared_ptr< Operator > oper) : Token() {
    _value.oper = oper.get();
    _type = Type::OPERATOR;
}


Token::Token(std::shared_ptr< Function > func) : Token() {
    _value.func = func.get();
    _type = Type::FUNCTION;
}


Token::Token(char parenthesis) : Token() {
    if (parenthesis == '(') {
        _type = Type::LEFTPARENTHESES;
    } else if (parenthesis == ')') {
        _type = Type::RIGHTPARENTHESES;
    } else {
        throw InvalidInput("Excepted parenthesis");
    }
}
