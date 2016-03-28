#include "../../core/types.h"
#include "../../core/concurrency.h"
#include "inverse.h"

namespace manipulation {
namespace filter {

void Inverse::apply(model::Image *&image) {
    core::parallelFor(0, image->pixelsCount(), [&image](unsigned p) {
        int x = p % image->width();
        int y = p / image->width();

        image->setRed(x, y, core::BYTE_MAX-image->red(x, y));
        image->setGreen(x, y, core::BYTE_MAX-image->green(x, y));
        image->setBlue(x, y, core::BYTE_MAX-image->blue(x, y));
    });
}
}
}
