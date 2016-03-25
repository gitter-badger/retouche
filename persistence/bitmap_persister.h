#ifndef PERSISTENCE_BITMAP_PERSISTER_H
#define PERSISTENCE_BITMAP_PERSISTER_H

#include "../core/types.h"
#include "../model/image.h"
#include "../include/bitmap_image.hpp"

namespace Persistence {

// Encapsulates a persister that could load and save bitmap images.
class BitmapPersister : public Persister {
public:
    Model::Image* load(const char *fileName) {
        bitmap_image bmp(fileName);

        Model::Image *image = new Model::Image(bmp.width(), bmp.height());

        for (unsigned x = 0; x < bmp.width(); ++x) {
            for (unsigned y = 0; y < bmp.height(); ++y) {
                byte red, green, blue;
                bmp.get_pixel(x, y, red, green, blue);

                image->setRed(x, y, red);
                image->setGreen(x, y, green);
                image->setBlue(x, y, blue);
            }
        }

        return image;
    }

    void save(Model::Image *image, const char *fileName) {
        bitmap_image bmp(image->width(), image->height());

        for (unsigned x = 0; x < bmp.width(); ++x) {
            for (unsigned y = 0; y < bmp.height(); ++y) {
                if (image->alpha(x, y) == BYTE_MAX) {
                    bmp.set_pixel(x, y,
                                  image->red(x, y),
                                  image->green(x, y),
                                  image->blue(x, y));
                } else {
                    bmp.set_pixel(x, y, BYTE_MIN, BYTE_MIN, BYTE_MIN);
                }
            }
        }

        bmp.save_image(fileName);
    }
};
}

#endif
