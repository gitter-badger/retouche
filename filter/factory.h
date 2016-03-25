#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include "operation.h"
#include "grayscale_filter.h"
#include "blur_filter.h"
#include "inverse_filter.h"

namespace Filter {

// Creates filter operations based on filter type name.
Operation* get(const std::string &type) {
    if (type == "grayscale") {
        return new GrayscaleFilter;
    } else if (type == "blur") {
        return new BlurFilter;
    } else if (type == "inverse") {
        return new InverseFilter;
    }
    return nullptr;
}
}

#endif
