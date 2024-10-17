#pragma once
#include "commands.h"
#include "figures_composite.h"


class Facade {
public:
    void execute(std::shared_ptr<Command> cmd);
    std::vector<std::shared_ptr<Command>>& getCommands();

private:
    std::shared_ptr<CompositeFigures> figures = std::make_shared<CompositeFigures>();

    std::vector<std::shared_ptr<Command>> commands;
    std::vector<std::shared_ptr<Command>>& cmds = commands;

    void initalizeCommands(std::vector<std::shared_ptr<Command>>& commands);
};



