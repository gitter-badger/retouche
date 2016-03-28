#include <iostream>
#include <exception>

#include "system.h"
#include "persistence/factory.h"
#include "manipulation/factory.h"

#define handle(name) if (command == #name) { name(parser); return; }
#define terminate(message) std::cerr << "ERROR: " << message << std::endl; exit(EXIT_FAILURE);
#define nullcheck(var, message) if (var == nullptr) { terminate(message) }

void System::execute(const std::string &command, core::CommandParser &parser) {
    try {
        handle(read)
        handle(from)
        handle(apply)
        handle(write)
        handle(to)
    } catch (std::exception &e) {
        terminate(e.what());
    }

    terminate("unknown command '" << command << "'")
}

void System::read(core::CommandParser &parser) {
    const std::string imageFormat = parser.next();
    persister = persistence::get(imageFormat);
    nullcheck(persister, "unknown read format '" << imageFormat << "'")
}

void System::from(core::CommandParser &parser) {
    if (persister == nullptr) {
        terminate("select image type before specifying the file")
    }

    const std::string fileName = parser.next();

    try {
        image = persister->load(fileName);
    } catch (std::exception &e) {
        terminate(e.what())
    }
}

void System::apply(core::CommandParser &parser) {
    if (image == nullptr) {
        terminate("read image from file before applying manipulations")
    }

    try {
        manipulation::Operation *operation = manipulation::get(parser);
        operation->apply(image);
    } catch (std::exception &e) {
        terminate(e.what())
    }
}

void System::write(core::CommandParser &parser) {
    const std::string imageFormat = parser.next();
    persister = persistence::get(imageFormat);
    nullcheck(persister, "unknown write format '" << imageFormat << "'")
}

void System::to(core::CommandParser &parser) {
    if (persister == nullptr) {
        terminate("select image type before specifying the file")
    }

    const std::string fileName = parser.next();

    try {
        persister->save(image, fileName);
    } catch (std::exception &e) {
        terminate(e.what())
    }
}
