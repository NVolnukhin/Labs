#ifndef COMMAND_CALCULATE_H
#define COMMAND_CALCULATE_H

#include "command.h"
#include <string>

template <typename Reciever>

class CommandCalculate : public Command<Reciever> {
    using Action = void(Reciever::*)(std::string);

public:
    CommandCalculate(Action action, std::string expression) : _action(action), _expression(expression) { }

    void execute(std::shared_ptr<Reciever> reciever) override {
        ((*reciever).*_action)(_expression);
    }

private:
    Action _action;
    std::string _expression;
};

#endif // COMMAND_CALCULATE_H
