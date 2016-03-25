#ifndef JPEG_PERSISTER_H
#define JPEG_PERSISTER_H

#include "../model/image.h"

namespace Persistence {

// Encapsulates a persister that could load and save JPEG images.
class JpegPersister : public Persister {
public:
    Model::Image* load(const char *fileName) {
        // Not implemented.
        return new Model::Image(0, 0);
    }

    void save(Model::Image *image, const char *fileName) {
        // Not implemented.
    }
};
}

#endif
