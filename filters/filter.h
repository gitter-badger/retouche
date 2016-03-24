#ifndef FILTER_H
#define FILTER_H

#include "../model/image.h"

namespace Filters {
class Filter {
public:
    virtual void apply(Model::Image *image) = 0;
};
}

#endif
