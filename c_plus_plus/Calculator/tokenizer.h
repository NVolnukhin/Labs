#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"
#include <iostream>
#include <stack>

using namespace TokenSpace;

class Tokenizer {
public:
    std::shared_ptr<std::vector<Token>> tokenize(const std::string& expr);
    std::shared_ptr<std::vector<Token>> tokenizeTest(const std::string& expression);
    std::shared_ptr<std::vector<Token>> convertToRpn(std::shared_ptr< std::vector<Token>> tokens);

private:
    std::string getNumber(std::string::const_iterator& it, std::string::const_iterator end);
    std::string getName(std::string::const_iterator& it, std::string::const_iterator end);
};

#endif // TOKENIZER_H
