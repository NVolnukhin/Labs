#include "command_delete_by_perimeter.h"
#include "float_input_manager.h"

void CommandDeleteFigureByPerimeter::execute(std::shared_ptr<CompositeFigures> figures) {
    double maxPerimeter;
    int counter = 0;
    floatInputManager mng;

    if ((int)figures->getSize() == 0)
        std::cout << "There's no figures" << std::endl;
    else {
        std::cout << "Input the maximum perimeter" << std::endl;
        double& refMaxPerimeter {maxPerimeter};
        mng.GetDouble(refMaxPerimeter);

        std::vector<std::shared_ptr<Figure>>& gottenFigures = figures->getFigures();
        for (int i = (int)figures->getSize() - 1; i >= 0; i--) {
            if (gottenFigures[i]->getPerimeter() > maxPerimeter) {
                figures->deleteFigure(i);
                counter++;
            }
        }

        if (counter == 0) {
            std::cout << "All figures have perimeter less than " << maxPerimeter << "\n" << std::endl;
        } else if (counter == 1) {
            std::cout << "Deleted " << counter << " figure\n" << std::endl;
        } else {
            std::cout << "Deleted " << counter << " figures\n" << std::endl;
        }
    }
};
