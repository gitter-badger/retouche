#include <cstring>

#include "system.h"
#include "core/command_parser.h"

int main(int argc, char **argv) {
    System system;
    for (unsigned i = 1; i < argc; ++i) {
        core::CommandParser parser(argv[i]);
        system.execute(parser.next(), parser);
    }
}
