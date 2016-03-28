#ifndef MANIPULATION_TRANSFORMATION_FLIP_H
#define MANIPULATION_TRANSFORMATION_FLIP_H

#include "../../core/types.h"
#include "../../core/concurrency.h"
#include "../../model/image.h"
#include "../operation.h"

namespace manipulation {
namespace transformation {

// Encapsulates a horizontal/vertical image flip operation.
class Flip : public Operation {
public:
    enum Type { horizontal, vertical };

    Flip(Type type): _type(type) {}

    void apply(model::Image *&image) {
        if (_type == Type::horizontal) {
            core::parallelFor(0, image->width()/2, [&image](unsigned x) {
                unsigned xInversed = image->width() - x - 1;
                for (unsigned y = 0; y < image->height(); y++) {
                    core::byte red = image->red(x, y),
                               green = image->green(x, y),
                               blue = image->blue(x, y),
                               alpha = image->alpha(x, y);

                    image->setRed(x, y, image->red(xInversed, y));
                    image->setGreen(x, y, image->green(xInversed, y));
                    image->setBlue(x, y, image->blue(xInversed, y));
                    image->setAlpha(x, y, image->alpha(xInversed, y));

                    image->setRed(xInversed, y, red);
                    image->setGreen(xInversed, y, green);
                    image->setBlue(xInversed, y, blue);
                    image->setAlpha(xInversed, y, alpha);
                }
            });
        } else if (_type == Type::vertical) {
            core::parallelFor(0, image->height()/2, [&image](unsigned y) {
                unsigned yInversed = image->height() - y - 1;
                for (unsigned x = 0; x < image->width(); x++) {
                    core::byte red = image->red(x, y),
                               green = image->green(x, y),
                               blue = image->blue(x, y),
                               alpha = image->alpha(x, y);

                    image->setRed(x, y, image->red(x, yInversed));
                    image->setGreen(x, y, image->green(x, yInversed));
                    image->setBlue(x, y, image->blue(x, yInversed));
                    image->setAlpha(x, y, image->alpha(x, yInversed));

                    image->setRed(x, yInversed, red);
                    image->setGreen(x, yInversed, green);
                    image->setBlue(x, yInversed, blue);
                    image->setAlpha(x, yInversed, alpha);
                }
            });
        }
    }

private:
    Type _type;
};
}
}

#endif
