#ifndef PERSISTENCE_JPEG_PERSISTER_H
#define PERSISTENCE_JPEG_PERSISTER_H

#include "../model/image.h"
#include "persister.h"

namespace persistence {

// Encapsulates a persister that could load and save JPEG images.
class JpegPersister : public Persister {
public:
    model::Image* load(const char *fileName);
    void save(model::Image *image, const char *fileName);
};
}

#endif
