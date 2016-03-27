#ifndef MANIPULATION_OPERATION_H
#define MANIPULATION_OPERATION_H

#include "../model/image.h"

namespace manipulation {

// Encapsulates a manipulation operation that could be applied to images.
class Operation {
public:
    // Applies the manipulation to a specific image.
    virtual void apply(model::Image *&image) = 0;
};
}

#endif
