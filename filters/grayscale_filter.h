#ifndef GRAYSCALE_FILTER_H
#define GRAYSCALE_FILTER_H

#include <thread>

#include "../model/image.h"

namespace Filters {
class GrayscaleFilter : public Filter {
public:
    void apply(Model::Image *image) {
        unsigned int poolSize = std::thread::hardware_concurrency();
        std::thread *pool = new std::thread[poolSize];

        unsigned int pieceWidth = image->width() / poolSize;
        for (unsigned int i = 0; i < poolSize; i++) {
            unsigned int startX = i * pieceWidth;
            unsigned int endX = startX + pieceWidth;
            if (i == poolSize - 1) {
                // Last thread should finish the image.
                endX = image->width();
            }

            pool[i] = std::thread(GrayscaleFilter::luminosity, image, startX, endX);
        }

        for (unsigned int i = 0; i < poolSize; i++) {
            pool[i].join();
        }
    }

private:
    static void luminosity(Model::Image *image, unsigned int startX, unsigned int endX) {
        for (unsigned int x = startX; x < endX; x++) {
            for (unsigned int y = 0; y < image->height(); y++) {
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
