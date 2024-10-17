#include "command_input_manager.h"
#include "facade.h"


int main() {
    Facade facade;
    auto& commands = facade.getCommands();
    commandInputManager mng;
    unsigned int cmd;
    float a = 4.;
    do {
        cmd = mng.GetCommand();
        facade.execute(commands[cmd]);
    } while (cmd != EXIT);
}



