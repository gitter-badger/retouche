#ifndef GRAYSCALE_FILTER_H
#define GRAYSCALE_FILTER_H

#include "../persistence/persister.h"

namespace Filters {
class GrayscaleFilter : public Filter {
public:
    void apply(Persistence::Image *image) {
        for (unsigned int x = 0; x < image->getWidth(); x++) {
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
