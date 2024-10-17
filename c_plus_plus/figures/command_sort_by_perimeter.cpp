#include "command_sort_by_perimeter.h"

void CommandSortFiguresByPerimeter::execute(std::shared_ptr<CompositeFigures> figures) {
    if ((int)figures->getSize() == 0)
        std::cout << "There's no figures" << std::endl;
    else {
        std::vector<std::shared_ptr<Figure>>& gottenFigures = figures->getFigures();

        std::sort(gottenFigures.begin(), gottenFigures.end(), [](std::shared_ptr<Figure>& f1, std::shared_ptr<Figure>& f2) {
            return (f1->getPerimeter() < f2->getPerimeter());
        });
        std::cout << "\nFigures are sorted\n" << std::endl;
    }
};
