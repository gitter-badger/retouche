#ifndef PERSISTENCE_JPEG_PERSISTER_H
#define PERSISTENCE_JPEG_PERSISTER_H

#include "persister.h"

namespace persistence {

// Encapsulates a persister that could load and save JPEG images.
class JpegPersister : public Persister {
public:
    model::Image* load(const std::string &fileName);
    void save(model::Image *image, const std::string &fileName);
};
}

#endif
