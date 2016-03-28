#ifndef MANIPULATION_FILTER_BLUR_H
#define MANIPULATION_FILTER_BLUR_H

#include "../../model/image.h"
#include "../operation.h"

namespace manipulation {
namespace filter {

// Encapsulates a Gaussian blur filter combines the colors of adjacent
// pixels using a Gaussian distribution.
class Blur : public Operation {
public:
    void apply(model::Image *&image);

private:
    double** computeKernel(unsigned size);
};
}
}

#endif
