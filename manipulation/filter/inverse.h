#ifndef MANIPULATION_FILTER_INVERSE_H
#define MANIPULATION_FILTER_INVERSE_H

#include "../../model/image.h"
#include "../operation.h"

namespace manipulation {
namespace filter {

// Encapsulates an inverse color filter operation that inverses the
// colors of an image.
class Inverse : public Operation {
public:
    void apply(model::Image *&image);
};
}
}

#endif
