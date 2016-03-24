#ifndef BLUR_FILTER_H
#define BLUR_FILTER_H

#include "../model/image.h"

namespace Filters {
class BlurFilter : public Filter {
public:
    void apply(Model::Image *image) {
        float kernel[3][3] = {
            0.0625, 0.125, 0.0625,
            0.125, 0.25, 0.125,
            0.0625, 0.125, 0.0625,
        };

        Model::Color *reds = new Model::Color[image->width() * image->height()];
        Model::Color *greens = new Model::Color[image->width() * image->height()];
        Model::Color *blues = new Model::Color[image->width() * image->height()];

        for(int x=0; x < image->width(); x++) {
            for(int y = 0; y < image->height(); y++) {
                double red = 0.0, green = 0.0, blue = 0.0;

                red += image->red(x, y)*kernel[1][1];
                green += image->green(x, y)*kernel[1][1];
                blue += image->blue(x, y)*kernel[1][1];

                if (x + 1 < image->width()) {
                    red += image->red(x+1, y) * kernel[2][1];
                    green += image->green(x+1, y) * kernel[2][1];
                    blue += image->blue(x+1, y) * kernel[2][1];

                    if (y + 1 < image->height()) {
                        red += image->red(x+1, y+1) * kernel[2][2];
                        green += image->green(x+1, y+1) * kernel[2][2];
                        blue += image->blue(x+1, y+1) * kernel[2][2];
                    }

                    if (y - 1 > 0) {
                        red += image->red(x+1, y-1) * kernel[2][0];
                        green += image->green(x+1, y-1) * kernel[2][0];
                        blue += image->blue(x+1, y-1) * kernel[2][0];
                    }
                }

                if (x - 1 > 0) {
                    red += image->red(x-1, y) * kernel[0][1];
                    green += image->green(x-1, y) * kernel[0][1];
                    blue += image->blue(x-1, y) * kernel[0][1];

                    if (y + 1 < image->height()) {
                        red += image->red(x-1, y+1) * kernel[0][2];
                        green += image->green(x-1, y+1) * kernel[0][2];
                        blue += image->blue(x-1, y+1) * kernel[0][2];
                    }

                    if (y - 1 > 0) {
                        red += image->red(x-1, y-1) * kernel[0][0];
                        green += image->green(x-1, y-1) * kernel[0][0];
                        blue += image->blue(x-1, y-1) * kernel[0][0];
                    }
                }

                if (y + 1 < image->height()) {
                    red += image->red(x, y+1) * kernel[1][2];
                    green += image->green(x, y+1) * kernel[1][2];
                    blue += image->blue(x, y+1) * kernel[1][2];
                }

                if (y - 1 > 0) {
                    red += image->red(x, y-1) * kernel[1][0];
                    green += image->green(x, y-1) * kernel[1][0];
                    blue += image->blue(x, y-1) * kernel[1][0];
                }

                reds[x * image->height() + y] = (Model::Color)(red);
                greens[x * image->height() + y] = (Model::Color)(green);
                blues[x * image->height() + y] = (Model::Color)(blue);
            }
        }

        for(int x=0; x < image->width(); x++) {
            for(int y = 0; y < image->height(); y++) {
                image->setRed(x, y, reds[x * image->height() + y]);
                image->setGreen(x, y, greens[x * image->height() + y]);
                image->setBlue(x, y, blues[x * image->height() + y]);
            }
        }
    }
};
}

#endif
