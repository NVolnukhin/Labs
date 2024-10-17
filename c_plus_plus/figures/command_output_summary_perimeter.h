#pragma once
#include "commands.h"

class CommandOutputSummaryPerimeter : public Command {
public:
    void execute(std::shared_ptr<CompositeFigures> figures) override;
};
