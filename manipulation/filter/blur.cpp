#include <cmath>

#include "../../core/array.h"
#include "../../core/types.h"
#include "../../core/concurrency.h"
#include "blur.h"

namespace manipulation {
namespace filter {

void Blur::apply(model::Image *&image) {
    int kernelSize = 7;
    double **kernel = computeKernel(kernelSize);

    model::Image *blurred = new model::Image(image->width(), image->height());

    core::parallelFor(0, image->pixelsCount(),
    [&image, &blurred, &kernelSize, &kernel](unsigned p) {
        int x = p % image->width();
        int y = p / image->width();

        core::byte red = core::BYTE_MIN,
                   green = core::BYTE_MIN,
                   blue = core::BYTE_MIN;
        int radius = kernelSize/2;
        for(int i = -radius; i <= radius; i++) {
            for(int j = -radius; j <= radius; j++) {
                if (x+i >= 0 && x+i < image->width() &&
                        y+j >= 0 && y+j < image->height()) {

                    red += image->red(x+i, y+j)*kernel[i+radius][j+radius];
                    green += image->green(x+i, y+j)*kernel[i+radius][j+radius];
                    blue += image->blue(x+i, y+j)*kernel[i+radius][j+radius];
                }
            }
        }

        blurred->setRed(x, y, red);
        blurred->setGreen(x, y, green);
        blurred->setBlue(x, y, blue);
    });

    delete image;
    image = blurred;
}

double** Blur::computeKernel(unsigned size) {
    double **kernel = new double*[size];
    for (unsigned i = 0; i < size; i++) {
        kernel[i] = new double[size];
    }

    double sigma = 1.0;
    double s = 2.0 * sigma * sigma;
    double sum = 0.0;

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            double r = std::sqrt((x-size/2)*(x-size/2) + (y-size/2)*(y-size/2));
            kernel[x][y] = (exp(-(r*r)/s))/(M_PI * s);
            sum += kernel[x][y];
        }
    }

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            kernel[x][y] /= sum;
        }
    }

    return kernel;
}
}
}
