#ifndef BLUR_FILTER_H
#define BLUR_FILTER_H

#include <thread>
#include <cmath>

#include "../persistence/persister.h"

namespace Filters {
class BlurFilter : public Filter {
public:
    void apply(Persistence::Image *image) {
        float kernel[3][3] = {
            0.0625, 0.125, 0.0625,
            0.125, 0.25, 0.125,
            0.0625, 0.125, 0.0625,
        };

        unsigned char *reds = new unsigned char[image->getWidth() * image->getHeight()];
        unsigned char *greens = new unsigned char[image->getWidth() * image->getHeight()];
        unsigned char *blues = new unsigned char[image->getWidth() * image->getHeight()];

        for(int x=0; x < image->getWidth(); x++) {
            for(int y = 0; y < image->getHeight(); y++) {
                double red = 0.0, green = 0.0, blue = 0.0;

                red += image->getRed(x, y)*kernel[1][1];
                green += image->getGreen(x, y)*kernel[1][1];
                blue += image->getBlue(x, y)*kernel[1][1];

                if (x + 1 < image->getWidth()) {
                    red += image->getRed(x+1, y) * kernel[2][1];
                    green += image->getGreen(x+1, y) * kernel[2][1];
                    blue += image->getBlue(x+1, y) * kernel[2][1];

                    if (y + 1 < image->getHeight()) {
                        red += image->getRed(x+1, y+1) * kernel[2][2];
                        green += image->getGreen(x+1, y+1) * kernel[2][2];
                        blue += image->getBlue(x+1, y+1) * kernel[2][2];
                    }

                    if (y - 1 > 0) {
                        red += image->getRed(x+1, y-1) * kernel[2][0];
                        green += image->getGreen(x+1, y-1) * kernel[2][0];
                        blue += image->getBlue(x+1, y-1) * kernel[2][0];
                    }
                }

                if (x - 1 > 0) {
                    red += image->getRed(x-1, y) * kernel[0][1];
                    green += image->getGreen(x-1, y) * kernel[0][1];
                    blue += image->getBlue(x-1, y) * kernel[0][1];

                    if (y + 1 < image->getHeight()) {
                        red += image->getRed(x-1, y+1) * kernel[0][2];
                        green += image->getGreen(x-1, y+1) * kernel[0][2];
                        blue += image->getBlue(x-1, y+1) * kernel[0][2];
                    }

                    if (y - 1 > 0) {
                        red += image->getRed(x-1, y-1) * kernel[0][0];
                        green += image->getGreen(x-1, y-1) * kernel[0][0];
                        blue += image->getBlue(x-1, y-1) * kernel[0][0];
                    }
                }

                if (y + 1 < image->getHeight()) {
                    red += image->getRed(x, y+1) * kernel[1][2];
                    green += image->getGreen(x, y+1) * kernel[1][2];
                    blue += image->getBlue(x, y+1) * kernel[1][2];
                }

                if (y - 1 > 0) {
                    red += image->getRed(x, y-1) * kernel[1][0];
                    green += image->getGreen(x, y-1) * kernel[1][0];
                    blue += image->getBlue(x, y-1) * kernel[1][0];
                }

                reds[x * image->getHeight() + y] = (unsigned char)(red);
                greens[x * image->getHeight() + y] = (unsigned char)(green);
                blues[x * image->getHeight() + y] = (unsigned char)(blue);
            }
        }

        for(int x=0; x < image->getWidth(); x++) {
            for(int y = 0; y < image->getHeight(); y++) {
                image->setRed(x, y, reds[x * image->getHeight() + y]);
                image->setGreen(x, y, greens[x * image->getHeight() + y]);
                image->setBlue(x, y, blues[x * image->getHeight() + y]);
            }
        }
    }
};
}

#endif
