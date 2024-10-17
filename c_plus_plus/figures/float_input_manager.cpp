#include "float_input_manager.h"

void floatInputManager::GetDouble(double& value) {
    std::cin >> value;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "You entered an incorrect value. Enter float" << std::endl;
        std::cin >> value;
    }
};


void floatInputManager::GetPositiveDouble(double& value) {
    std::cin >> value;
    while (std::cin.fail() || value < 0) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "You entered an incorrect value. Enter positive float" << std::endl;
        std::cin >> value;
    }
};
