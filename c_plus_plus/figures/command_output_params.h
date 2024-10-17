#pragma once
#include "commands.h"

class CommandOutputFiguresParams : public Command {
public:
    void execute(std::shared_ptr<CompositeFigures> figures) override;
};
