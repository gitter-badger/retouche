#include <cstring>

#include "operation.h"

namespace manipulation {

// Creates manipulation operations based on manipulation name.
Operation* get(const std::string &type);
}
