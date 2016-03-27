#ifndef MANIPULATION_INVERT_FILTER_H
#define MANIPULATION_INVERT_FILTER_H

#include "../core/types.h"
#include "../core/concurrency.h"
#include "../model/image.h"
#include "operation.h"

namespace manipulation {

// Encapsulates an inverse color filter operation that inverses the
// colors of an image.
class InverseFilter : public Operation {
public:
    void apply(model::Image *&image) {
        core::parallelFor(0, image->pixelsCount(), [&image](unsigned p) {
            int x = p % image->width();
            int y = p / image->width();

            image->setRed(x, y, core::BYTE_MAX-image->red(x, y));
            image->setGreen(x, y, core::BYTE_MAX-image->green(x, y));
            image->setBlue(x, y, core::BYTE_MAX-image->blue(x, y));
        });
    }
};
}

#endif
