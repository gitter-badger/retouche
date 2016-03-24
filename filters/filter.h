#ifndef FILTER_H
#define FILTER_H

#include "../persistence/persister.h"

namespace Filters {
class Filter {
public:
    virtual void apply(Persistence::Image *image) = 0;
};
}

#endif
