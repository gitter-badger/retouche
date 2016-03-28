#include "exceptions.h"

namespace manipulation {

UnknownManipulationException::UnknownManipulationException(const std::string &name) : _name(name) {}

const char* UnknownManipulationException::what() const throw() {
    std::string description = "unknown manipulation '";
    description.append(_name);
    description.append("'");
    return description.c_str();
}
}
