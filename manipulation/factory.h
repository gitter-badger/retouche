#ifndef MANIPULATION_FACTORY_H
#define MANIPULATION_FACTORY_H

#include <cstring>

#include "operation.h"
#include "grayscale_filter.h"
#include "blur_filter.h"
#include "inverse_filter.h"
#include "flip_operation.h"

namespace Manipulation {

// Creates manipulation operations based on manipulation name.
Operation* get(const std::string &type) {
    if (type == "grayscale") {
        return new GrayscaleFilter;
    } else if (type == "blur") {
        return new BlurFilter;
    } else if (type == "inverse") {
        return new InverseFilter;
    } else if (type == "flip") {
        const char *argument = strtok(nullptr, ":");
        if (strcmp(argument, "horizontal") == 0) {
            return new FlipOperation(FlipOperation::Type::horizontal);
        } else if (strcmp(argument, "vertical") == 0) {
            return new FlipOperation(FlipOperation::Type::vertical);
        }
    }
    return nullptr;
}
}

#endif
