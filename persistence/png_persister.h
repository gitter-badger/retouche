#ifndef PERSISTENCE_PNG_PERSISTER_H
#define PERSISTENCE_PNG_PERSISTER_H

#include <vector>

#include "../model/image.h"
#include "../include/lodepng.h"

namespace Persistence {

// Encapsulates a persister that could load and save PNG images.
class PNGPersister : public Persister {
public:
    Model::Image* load(const char *fileName) {
        std::vector<byte> pixels;
        unsigned width, height;

        lodepng::decode(pixels, width, height, fileName);

        Model::Image *image = new Model::Image(width, height);

        for (unsigned y = 0; y < height; ++y) {
            for (unsigned x = 0; x < width; ++x) {
                image->setRed(x, y, pixels[(y * width + x) * 4 + 0]);
                image->setGreen(x, y, pixels[(y * width + x) * 4 + 1]);
                image->setBlue(x, y, pixels[(y * width + x) * 4 + 2]);
                image->setAlpha(x, y, pixels[(y * width + x) * 4 + 3]);
            }
        }

        return image;
    }

    void save(Model::Image *image, const char *fileName) {
        std::vector<byte> png;
        std::vector<byte> pixels;

        for (unsigned y = 0; y < image->height(); y++) {
            for (unsigned x = 0; x < image->width(); x++) {
                pixels.push_back(image->red(x, y));
                pixels.push_back(image->green(x, y));
                pixels.push_back(image->blue(x, y));
                pixels.push_back(image->alpha(x, y));
            }
        }

        lodepng::encode(png, pixels, image->width(), image->height());
        lodepng::save_file(png, fileName);
    }
};
}

#endif
