#include <iostream>
#include <cstring>

#include "system.h"
#include "persistence/factory.h"
#include "filter/factory.h"

void System::execute(const char *command, const char *value) {
    if (strcmp(command, "read") == 0) {
        persister = Persistence::get(value);
        nullcheck(persister, "unknown read format '" << value << "'")
    } else if (strcmp(command, "from") == 0) {
        image = persister->load(value);
    } else if (strcmp(command, "apply") == 0) {
        Filter::Operation *operation = Filter::get(value);
        nullcheck(operation, "unknown filter '" << value << "'")

        operation->apply(image);
    } else if (strcmp(command, "write") == 0) {
        persister = Persistence::get(value);
        nullcheck(persister, "unknown write format '" << value << "'")
    } else if (strcmp(command, "to") == 0) {
        persister->save(image, value);
    } else {
        stop("unknown command '" << command << "'")
    }
}
