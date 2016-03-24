#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include "filter.h"
#include "grayscale_filter.h"
#include "blur_filter.h"
#include "inverse_filter.h"

namespace Filter {
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
