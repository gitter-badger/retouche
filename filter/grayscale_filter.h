#ifndef GRAYSCALE_FILTER_H
#define GRAYSCALE_FILTER_H

#include <thread>

#include "../model/image.h"

namespace Filter {
class GrayscaleFilter : public Operation {
public:
    void apply(Model::Image *image) {
        unsigned poolSize = std::thread::hardware_concurrency();
        std::thread *pool = new std::thread[poolSize];

        unsigned pieceWidth = image->width() / poolSize;
        for (unsigned i = 0; i < poolSize; i++) {
            unsigned startX = i * pieceWidth;
            unsigned endX = startX + pieceWidth;
            if (i == poolSize - 1) {
                // Last thread should finish the image.
                endX = image->width();
            }

            pool[i] = std::thread(GrayscaleFilter::luminosity, image, startX, endX);
        }

        for (unsigned i = 0; i < poolSize; i++) {
            pool[i].join();
        }
    }

private:
    static void luminosity(Model::Image *image, unsigned startX, unsigned endX) {
        for (unsigned x = startX; x < endX; x++) {
            for (unsigned y = 0; y < image->height(); y++) {
                Model::Color grayscaled = 0.21 * image->red(x, y) +
                                          0.72 * image->green(x, y) +
                                          0.07 * image->blue(x, y);

                image->setRed(x, y, grayscaled);
                image->setGreen(x, y, grayscaled);
                image->setBlue(x, y, grayscaled);
            }
        }
    }
};
}

#endif
