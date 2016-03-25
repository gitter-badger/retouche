#ifndef PERSISTENCE_FACTORY_H
#define PERSISTENCE_FACTORY_H

#include "persister.h"
#include "bitmap_persister.h"
#include "jpeg_persister.h"

namespace Persistence {

// Creates a persister based on file type name.
Persister* get(const std::string &fileType) {
    if (fileType == "bmp") {
        return new BitmapPersister;
    }
    // Not implemented:
    /* else if (fileType == "jpeg") {
        return new JpegPersister;
    } */
    return nullptr;
}
}

#endif
