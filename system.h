#ifndef SYSTEM_H
#define SYSTEM_H

#include "model/image.h"
#include "persistence/persister.h"

// Encapsulates a state machine that orchestrates the execution of the program.
class System {
public:
    // Executes a command with specific value parameter.
    void execute(const char *command, const char *value);

private:
    // Performs a read operation.
    void read(const char *value);

    // Performs a from operation.
    void from(const char *value);

    // Performs an apply operation.
    void apply(const char *value);

    // Performs a write operation.
    void write(const char *value);

    // Performs a to operation.
    void to(const char *value);

    Persistence::Persister *persister;
    Model::Image *image;
};

#endif
