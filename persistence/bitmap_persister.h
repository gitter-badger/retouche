#ifndef PERSISTENCE_BITMAP_PERSISTER_H
#define PERSISTENCE_BITMAP_PERSISTER_H

#include "../core/types.h"
#include "../model/image.h"
#include "../include/bitmap_image.hpp"

namespace persistence {

// Encapsulates a persister that could load and save bitmap images.
class BitmapPersister : public Persister {
public:
    model::Image* load(const char *fileName) {
        bitmap_image bmp(fileName);

        model::Image *image = new model::Image(bmp.width(), bmp.height());

        for (unsigned x = 0; x < bmp.width(); ++x) {
            for (unsigned y = 0; y < bmp.height(); ++y) {
                core::byte red, green, blue;
                bmp.get_pixel(x, y, red, green, blue);

                image->setRed(x, y, red);
                image->setGreen(x, y, green);
                image->setBlue(x, y, blue);
            }
        }

        return image;
    }

    void save(model::Image *image, const char *fileName) {
        bitmap_image bmp(image->width(), image->height());

        for (unsigned x = 0; x < bmp.width(); ++x) {
            for (unsigned y = 0; y < bmp.height(); ++y) {
                if (image->alpha(x, y) == core::BYTE_MAX) {
                    bmp.set_pixel(x, y,
                                  image->red(x, y),
                                  image->green(x, y),
                                  image->blue(x, y));
                } else {
                    bmp.set_pixel(x, y, core::BYTE_MIN, core::BYTE_MIN, core::BYTE_MIN);
                }
            }
        }

        bmp.save_image(fileName);
    }
};
}

#endif
