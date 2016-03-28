#include <vector>

#include "png_persister.h"
#include "../include/lodepng.h"

namespace persistence {

model::Image* PNGPersister::load(const std::string &fileName) {
    std::vector<core::byte> pixels;
    unsigned width, height;

    lodepng::decode(pixels, width, height, fileName);

    model::Image *image = new model::Image(width, height);

    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < width; ++x) {
            unsigned pixelIndex = (y * width + x) * 4;

            image->setRed(x, y, pixels[pixelIndex]);
            image->setGreen(x, y, pixels[pixelIndex + 1]);
            image->setBlue(x, y, pixels[pixelIndex + 2]);
            image->setAlpha(x, y, pixels[pixelIndex + 3]);
        }
    }

    return image;
}

void PNGPersister::save(model::Image *image, const std::string &fileName) {
    std::vector<core::byte> png;
    std::vector<core::byte> pixels;

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
}
