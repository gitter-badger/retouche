#ifndef SYSTEM_H
#define SYSTEM_H

#include "model/image.h"
#include "persistence/persister.h"

class System {
public:
    void execute(const char *command, const char *value);

private:
    void read(const char *value);
    void from(const char *value);
    void apply(const char *value);
    void write(const char *value);
    void to(const char *value);

    Persistence::Persister *persister;
    Model::Image *image;
};

#endif
