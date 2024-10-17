#pragma once
#include "commands.h"

class CommandSortFiguresByPerimeter : public Command {
public:
    void execute(std::shared_ptr<CompositeFigures> figures) override;
};
