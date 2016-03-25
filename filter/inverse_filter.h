#ifndef FILTER_INVERT_FILTER_H
#define FILTER_INVERT_FILTER_H

#include "../core/types.h"
#include "../core/concurrency.h"
#include "../model/image.h"
#include "operation.h"

namespace Filter {

// Encapsulates an inverse color filter operation that inverses the
// colors of an image.
class InverseFilter : public Operation {
public:
    void apply(Model::Image *&image) {
        parallelFor(0, image->height(), [&image](unsigned y) -> void {
            for(unsigned x = 0; x < image->width(); x++) {
                image->setRed(x, y, BYTE_MAX-image->red(x, y));
                image->setGreen(x, y, BYTE_MAX-image->green(x, y));
                image->setBlue(x, y, BYTE_MAX-image->blue(x, y));
            }
        });
    }
};
}

#endif
