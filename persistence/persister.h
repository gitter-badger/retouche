#ifndef PERSISTER_H
#define PERSISTER_H

#include "../model/image.h"

namespace Persistence {
class Persister {
public:
    virtual Model::Image* load(const char *fileName) = 0;
    virtual void save(Model::Image *image, const char *fileName) = 0;
};
};

#endif
