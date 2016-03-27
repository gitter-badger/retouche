#ifndef MANIPULATION_GRAYSCALE_FILTER_H
#define MANIPULATION_GRAYSCALE_FILTER_H

#include "../core/types.h"
#include "../core/concurrency.h"
#include "../model/image.h"
#include "operation.h"

namespace Manipulation {

// Encapsulates a grayscale filter operation that converts the colors
// of an image to shades of gray.
class GrayscaleFilter : public Operation {
public:
    void apply(Model::Image *&image) {
        core::parallelFor(0, image->pixelsCount(), [&image](unsigned p) {
            int x = p % image->width();
            int y = p / image->width();

            core::byte grayscaled = 0.21 * image->red(x, y) +
                                    0.72 * image->green(x, y) +
                                    0.07 * image->blue(x, y);

            image->setRed(x, y, grayscaled);
            image->setGreen(x, y, grayscaled);
            image->setBlue(x, y, grayscaled);
        });
    }
};
}

#endif
