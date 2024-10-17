#include "integer_input_manager.h"


void integerInputManager::GetPositiveInt(unsigned int& value) {
    std::cin >> value;
    while (std::cin.fail() || value <= 0) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "You entered an incorrect value. Enter positive integer" << std::endl;
        std::cin >> value;
    }
};


void integerInputManager::GetInt(int& value) {
    std::cin >> value;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "You entered an incorrect value. Enter positive integer" << std::endl;
        std::cin >> value;
    }
};
