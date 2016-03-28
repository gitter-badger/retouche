#ifndef MANIPULATION_FILTER_GRAYSCALE_H
#define MANIPULATION_FILTER_GRAYSCALE_H

#include "../../model/image.h"
#include "../operation.h"

namespace manipulation {
namespace filter {

// Encapsulates a grayscale filter operation that converts the colors
// of an image to shades of gray.
class Grayscale : public Operation {
public:
    void apply(model::Image *&image);
};
}
}

#endif
