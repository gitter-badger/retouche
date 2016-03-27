#ifndef PERSISTENCE_JPEG_PERSISTER_H
#define PERSISTENCE_JPEG_PERSISTER_H

#include "../model/image.h"
#include "../include/jpgd.h"
#include "../include/jpge.h"

namespace Persistence {

// Encapsulates a persister that could load and save JPEG images.
class JpegPersister : public Persister {
public:
    Model::Image* load(const char *fileName) {
        int width, height, composition;
        core::byte *pixels = jpgd::decompress_jpeg_image_from_file(
                                 fileName, &width, &height, &composition, 4);

        Model::Image *image = new Model::Image(width, height);

        for (unsigned y = 0; y < height; ++y) {
            for (unsigned x = 0; x < width; ++x) {
                unsigned pixelIndex = (y * width + x) * 4;

                image->setRed(x, y, pixels[pixelIndex]);
                image->setGreen(x, y, pixels[pixelIndex + 1]);
                image->setBlue(x, y, pixels[pixelIndex + 2]);
                image->setAlpha(x, y, pixels[pixelIndex + 3]);
            }
        }

        delete []pixels;

        return image;
    }

    void save(Model::Image *image, const char *fileName) {
        core::byte *pixels = new core::byte[image->height() * image->width() * 4];

        for (unsigned y = 0; y < image->height(); y++) {
            for (unsigned x = 0; x < image->width(); x++) {
                unsigned pixelIndex = (y * image->width() + x) * 4;

                pixels[pixelIndex] = image->red(x, y);
                pixels[pixelIndex + 1] = image->green(x, y);
                pixels[pixelIndex + 2] = image->blue(x, y);
                pixels[pixelIndex + 3] = image->alpha(x, y);
            }
        }

        jpge::compress_image_to_jpeg_file(fileName, image->width(),
                                          image->height(), 4, pixels);

        delete []pixels;
    }
};
}

#endif
