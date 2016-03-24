#ifndef JPEG_PERSISTER_H
#define JPEG_PERSISTER_H

#include <iostream>

namespace Persistence {
class JpegImage : public Image {
public:
    JpegImage(unsigned int _width, unsigned int _height):
        Image(_width, _height) {}
};

class JpegPersister : public Persister {
public:
    Image* load(const char *fileName) {
        std::cout << "Loading jpeg" << std::endl;
        return new JpegImage(0, 0);
    }

    void save(Image *image, const char *fileName) {
        std::cout << "Saving jpeg" << std::endl;
    }
};
}

#endif
