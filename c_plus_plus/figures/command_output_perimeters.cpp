#include "command_output_perimeters.h"

void CommandOutputFiguresPerimeters::execute(std::shared_ptr<CompositeFigures> figures) {
    if ((int)figures->getSize() == 0)
        std::cout << "There's no figures\n" << std::endl;
    else {
        std::vector<std::shared_ptr<Figure>>& gottenFigures = figures->getFigures();
        for (int i = 0; i < (int)gottenFigures.size(); i++) {
            std::cout << i + 1 << ". ";
            gottenFigures[i]->printPerimeter();
        }
    }
};
