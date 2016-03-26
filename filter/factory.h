#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include <cstring>

#include "operation.h"
#include "grayscale_filter.h"
#include "blur_filter.h"
#include "inverse_filter.h"
#include "flip_filter.h"

namespace Filter {

// Creates filter operations based on filter type name.
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
            return new FlipFilter(FlipFilter::Type::horizontal);
        } else if (strcmp(argument, "vertical") == 0) {
            return new FlipFilter(FlipFilter::Type::vertical);
        }
    }
    return nullptr;
}
}

#endif
