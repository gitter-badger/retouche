#ifndef MANIPULATION_FACTORY_H
#define MANIPULATION_FACTORY_H

#include <cstring>

#include "operation.h"
#include "filter/grayscale.h"
#include "filter/blur.h"
#include "filter/inverse.h"
#include "transformation/flip.h"

namespace manipulation {

// Creates manipulation operations based on manipulation name.
Operation* get(const std::string &type) {
    if (type == "grayscale") {
        return new filter::Grayscale;
    } else if (type == "blur") {
        return new filter::Blur;
    } else if (type == "inverse") {
        return new filter::Inverse;
    } else if (type == "flip") {
        const char *argument = strtok(nullptr, ":");
        if (strcmp(argument, "horizontal") == 0) {
            return new transformation::Flip(
                       transformation::Flip::Type::horizontal);
        } else if (strcmp(argument, "vertical") == 0) {
            return new transformation::Flip(
                       transformation::Flip::Type::vertical);
        }
    }
    return nullptr;
}
}

#endif
