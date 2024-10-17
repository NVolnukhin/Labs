#include "command_delete_by_number.h"
#include "integer_input_manager.h"

bool CommandDeleteFigureByNumber::checkExistanceOfFigure(std::shared_ptr<CompositeFigures> figures, unsigned int num) {
    return num - 1 < (unsigned int)figures->getSize();
}

void CommandDeleteFigureByNumber::execute(std::shared_ptr<CompositeFigures> figures) {
    integerInputManager mng;
    unsigned int number;
    unsigned int& refNumber {number};

    if ((int)figures->getSize() == 0)
        std::cout << "There's no figures" << std::endl;
    else {
        std::cout << "Input  number of figure which you want to delete" << std::endl;
        mng.GetPositiveInt(refNumber);
        if (checkExistanceOfFigure(figures, number)) {
            figures->deleteFigure(number - 1);
            std::cout << "Figure " << number << " is deleted" << std::endl;
        } else
            std::cout << "There's no figure with this number" << std::endl;
    }
};
