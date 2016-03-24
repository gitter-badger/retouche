#ifndef JPEG_PERSISTER_H
#define JPEG_PERSISTER_H

#include <iostream>

namespace Persistence {
  class JpegImage : public Image {};

  class JpegPersister : public Persister {
    public:
      Image* load(const char *fileName) {
        std::cout << "Loading jpeg" << std::endl;
        return new JpegImage;
      }

      void save(Image *image, const char *fileName) {
        std::cout << "Saving jpeg" << std::endl;
      }
  };
}

#endif
