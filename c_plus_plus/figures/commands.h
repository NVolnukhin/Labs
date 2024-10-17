#pragma once

#include "figures_composite.h"
#include "points.h"


class Command {
public:
    virtual void execute(std::shared_ptr<CompositeFigures> figures) = 0;
};





