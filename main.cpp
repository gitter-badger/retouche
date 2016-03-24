#include <cstring>

#include "system.h"

int main(int argc, char **argv) {
    System system;
    for (int i = 1; i < argc; ++i) {
        char *command = strtok(argv[i], ":"), *value = strtok(nullptr, ":");
        system.execute(command, value);
    }
}
