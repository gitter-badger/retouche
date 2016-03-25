#ifndef GRAYSCALE_FILTER_H
#define GRAYSCALE_FILTER_H

#include <thread>

#include "../core/types.h"
#include "../core/concurrency.h"
#include "../model/image.h"

namespace Filter {
class GrayscaleFilter : public Operation {
public:
    void apply(Model::Image *image) {
        parallelFor(0, image->width(), 1, [&image](unsigned x) -> void {
            for (unsigned y = 0; y < image->height(); y++) {
                byte grayscaled = 0.21 * image->red(x, y) +
                0.72 * image->green(x, y) +
                0.07 * image->blue(x, y);

                image->setRed(x, y, grayscaled);
                image->setGreen(x, y, grayscaled);
                image->setBlue(x, y, grayscaled);
            }
        });
    }
};
}

#endif
