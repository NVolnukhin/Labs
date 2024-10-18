#ifndef FACADE_H
#define FACADE_H

#include <command.h>
#include <calculator_result.h>

template <typename Calculator>

class Facade {
public:
    void executeCommand(std::shared_ptr<Command<Calculator>> cmd) {
        auto calculator = std::make_shared<Calculator>();
        cmd->execute(calculator);
        _calcResult = calculator->getResult();
    }

    CalculatorResult getResult() {
        return _calcResult;
    }

private:
    CalculatorResult _calcResult;
};

#endif // FACADE_H
