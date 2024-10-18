#ifndef COMMAND_H
#define COMMAND_H

#include <memory>

template <typename Receiver>

class Command {
public:
    virtual void execute(std::shared_ptr<Receiver> reciever) = 0;

    virtual ~Command() = default;
};

#endif // COMMAND_H
