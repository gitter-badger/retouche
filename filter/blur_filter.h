#ifndef BLUR_FILTER_H
#define BLUR_FILTER_H

#include "../core/sized_array.h"
#include "../model/image.h"

namespace Filter {
class BlurFilter : public Operation {
public:
    void apply(Model::Image *image) {
        double kernel[3][3] = {
            {0.0625, 0.125, 0.0625,},
            {0.125, 0.25, 0.125,},
            {0.0625, 0.125, 0.0625,}
        };

        SizedArray<Model::Color> reds(image->width() * image->height()),
                   greens(image->width() * image->height()),
                   blues(image->width() * image->height());

        for(int x = 0; x < image->width(); x++) {
            for(int y = 0; y < image->height(); y++) {
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

                reds[x * image->height() + y] = static_cast<Model::Color>(red);
                greens[x * image->height() + y] = static_cast<Model::Color>(green);
                blues[x * image->height() + y] = static_cast<Model::Color>(blue);
            }
        }

        image->setReds(reds);
        image->setGreens(greens);
        image->setBlues(blues);
    }
};
}

#endif
