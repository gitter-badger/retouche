#include "../core/types.h"
#include "../include/bitmap_image.hpp"
#include "bitmap_persister.h"

namespace persistence {

model::Image* BitmapPersister::load(const std::string &fileName) {
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

void BitmapPersister::save(model::Image *image, const std::string &fileName) {
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
}
