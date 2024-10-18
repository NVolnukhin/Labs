#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "command_calculate.h"
#include <memory>

template <typename Calculator>

class CommandFactory {
public:
    static std::shared_ptr<CommandCalculate<Calculator>> createCalculateCommand(std::string expr) {
        return std::make_shared<CommandCalculate<Calculator>>(&Calculator::calculate, expr);
    }
};

#endif // COMMAND_FACTORY_H
