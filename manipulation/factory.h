#include <string>

#include "operation.h"
#include "../core/command_parser.h"

namespace manipulation {

// Creates manipulation operations based on manipulation name.
Operation* get(core::CommandParser &parser);
}
