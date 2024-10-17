#include "command_input_manager.h"
#include "integer_input_manager.h"

unsigned int commandInputManager::GetCommand() {
    int command;
    int& cmd = command;
    integerInputManager mng;
    std::cout << "\nWhat you want to do ?\n"
                 "1 - Add figure\n"
                 "2 - Output figures with their parameters\n"
                 "3 - Output figures with their perimeters\n"
                 "4 - Output figures summary perimeter\n"
                 "5 - Sort figures by perimeter in ascending power\n"
                 "6 - Delete figure by number\n"
                 "7 - Delete figures with perimeter bigger than...\n"
                 "0 - Exit\n\n"
                 "Input command" << std::endl;

    mng.GetInt(cmd);
    while (command < EXIT || command > DELETE_BY_PERIMETER) {
        std::cout << "Incorrect input. Input command in range from 0 to 7" << std::endl;
        mng.GetInt(cmd);
    }

    return command;
}

unsigned int commandInputManager::GetCreatingCommand() {
    unsigned int cmd;

    std::cout << "\nWhat figure do you want to add?\n"
                 "1 - Circle\n"
                 "2 - Rectangle\n"
                 "3 - Trinangle\n"
                 "4 - Polygon\n" << std::endl;

    std::cin >> cmd;
    while (std::cin.fail() || cmd < ADD_CIRCLE || cmd > ADD_POLYGON) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "You entered an incorrect value. Enter command in range of 1 to 4" << std::endl;
        std::cin >> cmd;
    }

    return cmd;
}
