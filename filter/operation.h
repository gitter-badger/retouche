#ifndef FILTER_OPERATION_H
#define FILTER_OPERATION_H

#include "../model/image.h"

namespace Filter {

// Encapsulates a filter operation that could be applied to images.
class Operation {
public:
    // Applies the filter to a specific image.
    virtual void apply(Model::Image *image) = 0;
};
}

#endif
