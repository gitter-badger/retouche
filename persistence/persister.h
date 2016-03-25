#ifndef PERSISTER_H
#define PERSISTER_H

#include "../model/image.h"

namespace Persistence {

// Encapsulates a persister that could load and save images.
class Persister {
public:
    // Loads the image file specified by the value of fileName.
    virtual Model::Image* load(const char *fileName) = 0;

    // Saves image to a file with named with the value of fileName.
    virtual void save(Model::Image *image, const char *fileName) = 0;
};
};

#endif
