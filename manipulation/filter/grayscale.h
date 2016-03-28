#ifndef MANIPULATION_FILTER_GRAYSCALE_H
#define MANIPULATION_FILTER_GRAYSCALE_H

#include "../../core/types.h"
#include "../../core/concurrency.h"
#include "../../model/image.h"
#include "../operation.h"

namespace manipulation {
namespace filter {

// Encapsulates a grayscale filter operation that converts the colors
// of an image to shades of gray.
class Grayscale : public Operation {
public:
    void apply(model::Image *&image) {
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
}

#endif
