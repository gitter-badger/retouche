#include <iostream>
#include <cstring>
#include <exception>

#include "system.h"
#include "persistence/factory.h"
#include "manipulation/factory.h"

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
    try {
        image = persister->load(value);
    } catch (std::exception& e) {
        terminate(e.what())
    }
}

void System::apply(const char *value) {
    Manipulation::Operation *operation = Manipulation::get(value);
    nullcheck(operation, "unknown filter '" << value << "'")

    try {
        operation->apply(image);
    } catch (std::exception& e) {
        terminate(e.what())
    }
}

void System::write(const char *value) {
    persister = Persistence::get(value);
    nullcheck(persister, "unknown write format '" << value << "'")
}

void System::to(const char *value) {
    try {
        persister->save(image, value);
    } catch (std::exception& e) {
        terminate(e.what())
    }
}
