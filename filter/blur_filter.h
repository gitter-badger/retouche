#ifndef FILTER_BLUR_FILTER_H
#define FILTER_BLUR_FILTER_H

#include "../core/array.h"
#include "../core/types.h"
#include "../core/concurrency.h"
#include "../model/image.h"
#include "operation.h"

namespace Filter {

// Encapsulates a Gaussian blur filter combines the colors of adjacent
// pixels using a Gaussian distribution.
class BlurFilter : public Operation {
public:
    void apply(Model::Image *&image) {
        double kernel[3][3] = {
            {0.0625, 0.125, 0.0625,},
            {0.125, 0.25, 0.125,},
            {0.0625, 0.125, 0.0625,}
        };

        Model::Image *blurred = new Model::Image(image->width(), image->height());

        for (int y = 0; y < image->height(); y++) {
            for(int x = 0; x < image->width(); x++) {
                double red = 0.0, green = 0.0, blue = 0.0;

                for(int i = -1; i < 2; i++) {
                    for(int j = -1; j < 2; j++) {
                        if (x+i >= 0 && x+i < image->width() &&
                                y+j >= 0 && y+j < image->height()) {

                            red += image->red(x+i, y+j)*kernel[i+1][j+1];
                            green += image->green(x+i, y+j)*kernel[i+1][j+1];
                            blue += image->blue(x+i, y+j)*kernel[i+1][j+1];
                        }
                    }
                }

                blurred->setRed(x, y, static_cast<byte>(red));
                blurred->setGreen(x, y, static_cast<byte>(green));
                blurred->setBlue(x, y, static_cast<byte>(blue));
            }
        };

        delete image;
        image = blurred;
    }
};
}

#endif
