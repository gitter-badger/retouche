#include "../../core/types.h"
#include "../../core/concurrency.h"
#include "grayscale.h"

namespace manipulation {
namespace filter {

void Grayscale::apply(model::Image *&image) {
    core::parallelFor(0, image->pixelsCount(), [&image](unsigned p) {
        int x = p % image->width();
        int y = p / image->width();

        core::byte grayscaled = 0.21 * image->red(x, y) +
                                0.72 * image->green(x, y) +
                                0.07 * image->blue(x, y);

        image->setRed(x, y, grayscaled);
        image->setGreen(x, y, grayscaled);
        image->setBlue(x, y, grayscaled);
    });
}
}
}
