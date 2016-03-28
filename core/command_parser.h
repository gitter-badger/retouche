#ifndef CORE_COMMAND_PARSER_H
#define CORE_COMMAND_PARSER_H

#include <string>

namespace core {

// Parses command statements and returns consecutive tokens.
class CommandParser {
public:
    CommandParser(char *command);
    const std::string next();

private:
    char *seed;
};
}

#endif
