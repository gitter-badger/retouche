#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

#include "core/command_parser.h"
#include "model/image.h"
#include "persistence/persister.h"

// Encapsulates a state machine that orchestrates the execution of the program.
class System {
public:
    // Executes a command with specific value parameter.
    void execute(const std::string &command, core::CommandParser &parser);

private:
    // Performs a read operation.
    void read(core::CommandParser &parser);

    // Performs a from operation.
    void from(core::CommandParser &parser);

    // Performs an apply operation.
    void apply(core::CommandParser &parser);

    // Performs a write operation.
    void write(core::CommandParser &parser);

    // Performs a to operation.
    void to(core::CommandParser &parser);

    persistence::Persister *persister;
    model::Image *image;
};

#endif
