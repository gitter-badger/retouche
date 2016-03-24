#ifndef SYSTEM_H
#define SYSTEM_H

#include "model/image.h"
#include "persistence/persister.h"

#define stop(message) std::cerr << "ERROR: " << message << std::endl; exit(EXIT_FAILURE);
#define nullcheck(var, message) if (var == nullptr) { stop(message) }

class System {
public:
    void execute(const char *command, const char *value);

private:
    Persistence::Persister *persister;
    Model::Image *image;
};

#endif
