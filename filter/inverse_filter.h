#ifndef INVERT_FILTER_H
#define INVERT_FILTER_H

#include "../core/types.h"
#include "../model/image.h"
#include "operation.h"

namespace Filter {

// Encapsulates an inverse color filter operation that inverses the
// colors of an image.
class InverseFilter : public Operation {
public:
    void apply(Model::Image *image) {
        parallelFor(0, image->width(), [&image](unsigned w) -> void {
            for(unsigned h = 0; h < image->height(); h++) {
                image->setRed(w, h, BYTE_MAX-image->red(w, h));
                image->setGreen(w, h, BYTE_MAX-image->green(w, h));
                image->setBlue(w, h, BYTE_MAX-image->blue(w, h));
            }
        });
    }
};
}

#endif
