#include "facade.h"

#include "command_add_figure.h"
#include "command_sort_by_perimeter.h"
#include "command_delete_by_number.h"
#include "command_delete_by_perimeter.h"
#include "command_output_params.h"
#include "command_output_perimeters.h"
#include "command_output_summary_perimeter.h"
#include "command_exit.h"


void Facade::execute(std::shared_ptr<Command> cmd) {
    cmd->execute(figures);
}

std::vector<std::shared_ptr<Command>>& Facade::getCommands() {
    initalizeCommands(cmds);
    return cmds;
}

void Facade::initalizeCommands(std::vector<std::shared_ptr<Command>>& commands) {
    commands.push_back(std::make_shared<CommandExit>());
    commands.push_back(std::make_shared<CommandAddFigure>());
    commands.push_back(std::make_shared<CommandOutputFiguresParams>());
    commands.push_back(std::make_shared<CommandOutputFiguresPerimeters>());
    commands.push_back(std::make_shared<CommandOutputSummaryPerimeter>());
    commands.push_back(std::make_shared<CommandSortFiguresByPerimeter>());
    commands.push_back(std::make_shared<CommandDeleteFigureByNumber>());
    commands.push_back(std::make_shared<CommandDeleteFigureByPerimeter>());
}
