#include <stdexcept>
#include <cstring>

#include "command_parser.h"

namespace core {

CommandParser::CommandParser(char *command)  : seed(command) {}

const std::string CommandParser::next() {
    const char *token = strtok(seed, ":");
    if (token == nullptr) {
        throw std::invalid_argument("expected more tokens in command");
    }

    std::string result = token;
    seed = nullptr;
    return result;
}
}
