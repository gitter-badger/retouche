#ifndef PERSISTENCE_PERSISTER_H
#define PERSISTENCE_PERSISTER_H

#include <string>
#include "../model/image.h"

namespace persistence {

// Encapsulates a persister that could load and save images.
class Persister {
public:
    // Loads the image file specified by the value of fileName.
    virtual model::Image* load(const std::string &fileName) = 0;

    // Saves image to a file with named with the value of fileName.
    virtual void save(model::Image *image, const std::string &fileName) = 0;
};
};

#endif
