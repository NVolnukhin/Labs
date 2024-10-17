#pragma once
#include "commands.h"

class CommandDeleteFigureByNumber : public Command {
public:
    void execute(std::shared_ptr<CompositeFigures> figures) override;

private:
    static bool checkExistanceOfFigure(std::shared_ptr<CompositeFigures> figures, unsigned int num);
};
