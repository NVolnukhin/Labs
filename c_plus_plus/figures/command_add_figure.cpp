#include "command_add_figure.h"
#include "figures_factory.h"
#include "command_input_manager.h"

unsigned int CommandAddFigure::getCreatingCommand() {
    commandInputManager mng;
    return mng.GetCreatingCommand();
}

std::shared_ptr<Figure> CommandAddFigure::getFigure(unsigned int type) {
    FigureFactory f;
    if (type == ADD_CIRCLE)
        return f.createCircle();
    else if (type == ADD_RECTANGLE)
        return f.createRectangle();
    else if (type == ADD_TRIANGLE)
        return f.createTriangle();
    else if (type == ADD_POLYGON)
        return f.createPolygon();
    else throw std::exception();
}

void CommandAddFigure::execute(std::shared_ptr<CompositeFigures> figures) {
    unsigned int cmd = getCreatingCommand();

    auto figure = getFigure(cmd);
    while (!figure->validate()) {
        std::cout << "Incorrect input. Reinput figure please" << std::endl;
        figure = getFigure(cmd);
    }
    figures->addFigure(figure);
    std::cout << "Good input. Figure added" << std::endl;
}
