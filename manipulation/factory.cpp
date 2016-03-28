#include <cstring>

#include "factory.h"
#include "filter/grayscale.h"
#include "filter/blur.h"
#include "filter/inverse.h"
#include "transformation/flip.h"
#include "exceptions.h"

namespace manipulation {

// Creates manipulation operations based on manipulation name.
Operation* get(const std::string &type) {
    std::string manipulationName = type;

    if (type == "filter") {
        const std::string type = strtok(nullptr, ":");

        if (type == "grayscale") {
            return new filter::Grayscale;
        } else if (type == "blur") {
            return new filter::Blur;
        } else if (type == "inverse") {
            return new filter::Inverse;
        } else {
            manipulationName.append(":" + type);
        }
    } else if (type == "transformation") {
        const std::string type = strtok(nullptr, ":");

        if (type == "flip(horizontal)") {
            // FIXME: Change this when command arguments are introduced.
            return new transformation::Flip(transformation::Flip::Type::horizontal);
        } else if (type == "flip(vertical)") {
            // FIXME: Change this when command arguments are introduced.
            return new transformation::Flip(transformation::Flip::Type::vertical);
        } else {
            manipulationName.append(":" + type);
        }
    }

    throw UnknownManipulationException(manipulationName);
}
}
