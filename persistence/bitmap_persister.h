#ifndef BITMAP_PERSISTER_H
#define BITMAP_PERSISTER_H

#include <iostream>
#include "../include/bitmap_image.hpp"

namespace Persistence {
class BitmapImage : public Image {
public:
    BitmapImage(unsigned int _width, unsigned int _height):
        Image(_width, _height) {}
};

class BitmapPersister : public Persister {
public:
    Image* load(const char *fileName) {
        bitmap_image bmp(fileName);

        Image *image = new BitmapImage(bmp.width(), bmp.height());

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

    void save(Image *image, const char *fileName) {
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
