#ifndef GRAYSCALE_FILTER_H
#define GRAYSCALE_FILTER_H

#include <thread>

#include "../persistence/persister.h"

namespace Filters {
class GrayscaleFilter : public Filter {
public:
    void apply(Persistence::Image *image) {
        unsigned int poolSize = std::thread::hardware_concurrency();
        std::thread *pool = new std::thread[poolSize];

        unsigned int pieceWidth = image->getWidth() / poolSize;
        for (unsigned int i = 0; i < poolSize; i++) {
            unsigned int startX = i * pieceWidth;
            unsigned int endX = startX + pieceWidth;
            if (i == poolSize - 1) {
                // Last thread should finish the image.
                endX = image->getWidth();
            }

            pool[i] = std::thread(GrayscaleFilter::luminosity, image, startX, endX);
        }

        for (unsigned int i = 0; i < poolSize; i++) {
            pool[i].join();
        }
    }

private:
    static void luminosity(Persistence::Image *image, unsigned int startX, unsigned int endX) {
        for (unsigned int x = startX; x < endX; x++) {
            for (unsigned int y = 0; y < image->getHeight(); y++) {
                unsigned char grayscaled = 0.21 * image->getRed(x, y) +
                                           0.72 * image->getGreen(x, y) +
                                           0.07 * image->getBlue(x, y);

                image->setRed(x, y, grayscaled);
                image->setGreen(x, y, grayscaled);
                image->setBlue(x, y, grayscaled);
            }
        }
    }
};
}

#endif
