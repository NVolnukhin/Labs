#pragma once
#include "commands.h"

class CommandDeleteFigureByPerimeter : public Command {
public:
    void execute(std::shared_ptr<CompositeFigures> figures) override;
};
