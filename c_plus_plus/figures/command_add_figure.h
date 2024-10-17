#pragma once

#include "commands.h"

class CommandAddFigure : public Command {
public:
    void execute(std::shared_ptr<CompositeFigures> figures);
private:
    static std::shared_ptr<Figure> getFigure(unsigned int type);
    static unsigned int getCreatingCommand();
};
