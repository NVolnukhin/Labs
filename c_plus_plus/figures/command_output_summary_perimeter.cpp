#include "command_output_summary_perimeter.h"

void CommandOutputSummaryPerimeter::execute(std::shared_ptr<CompositeFigures> figures) {
    long double sum = 0;

    if ((int)figures->getSize() == 0)
        std::cout << "There's no figures\n" << std::endl;
    else {
        std::vector<std::shared_ptr<Figure>>& gottenFigures = figures->getFigures();
        std::cout << std::endl;
        for (int i = 0; i < (int)gottenFigures.size(); i++) {
            sum += gottenFigures[i]->getPerimeter();
        }

        std::cout << "\nSum of perimeters is " << sum << "\n"<< std::endl;
    }
};
