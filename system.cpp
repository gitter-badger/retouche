#include <iostream>
#include <cstring>

#include "system.h"
#include "persistence/factory.h"
#include "filter/factory.h"

#define handle(name) if (strcmp(command, #name) == 0) { name(value); return; }
#define terminate(message) std::cerr << "ERROR: " << message << std::endl; exit(EXIT_FAILURE);
#define nullcheck(var, message) if (var == nullptr) { terminate(message) }

void System::execute(const char *command, const char *value) {
    handle(read)
    handle(from)
    handle(apply)
    handle(write)
    handle(to)

    terminate("unknown command '" << command << "'")
}

void System::read(const char *value) {
    persister = Persistence::get(value);
    nullcheck(persister, "unknown read format '" << value << "'")
}

void System::from(const char *value) {
    image = persister->load(value);
}

void System::apply(const char *value) {
    Filter::Operation *operation = Filter::get(value);
    nullcheck(operation, "unknown filter '" << value << "'")

    operation->apply(image);
}

void System::write(const char *value) {
    persister = Persistence::get(value);
    nullcheck(persister, "unknown write format '" << value << "'")
}

void System::to(const char *value) {
    persister->save(image, value);
}
