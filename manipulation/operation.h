#ifndef MANIPULATION_OPERATION_H
#define MANIPULATION_OPERATION_H

#include "../model/image.h"

namespace Manipulation {

// Encapsulates a manipulation operation that could be applied to images.
class Operation {
public:
    // Applies the manipulation to a specific image.
    virtual void apply(Model::Image *&image) = 0;
};
}

#endif
