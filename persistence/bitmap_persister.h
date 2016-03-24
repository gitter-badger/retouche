#ifndef BITMAP_PERSISTER_H
#define BITMAP_PERSISTER_H

#include "../model/image.h"
#include "../include/bitmap_image.hpp"

namespace Persistence {
class BitmapPersister : public Persister {
public:
    Model::Image* load(const char *fileName) {
        bitmap_image bmp(fileName);

        Model::Image *image = new Model::Image(bmp.width(), bmp.height());

        for (std::size_t y = 0; y < bmp.height(); ++y)        {
            for (std::size_t x = 0; x < bmp.width(); ++x) {
                unsigned char red, green, blue;
                bmp.get_pixel(x, y, red, green, blue);

                image->setRed(x, y, red);
                image->setGreen(x, y, green);
                image->setBlue(x, y, blue);
            }
        }

        return image;
    }

    void save(Model::Image *image, const char *fileName) {
        bitmap_image bmp(image->getWidth(), image->getHeight());

        for (std::size_t y = 0; y < bmp.height(); ++y)        {
            for (std::size_t x = 0; x < bmp.width(); ++x) {
                bmp.set_pixel(x, y,
                              image->getRed(x, y),
                              image->getGreen(x, y),
                              image->getBlue(x, y));
            }
        }

        bmp.save_image(fileName);
    }
};
}

#endif
