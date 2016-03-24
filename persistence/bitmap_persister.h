#ifndef BITMAP_PERSISTER_H
#define BITMAP_PERSISTER_H

#include <iostream>

namespace Persistence {
  class BitmapImage : public Image {};

  class BitmapPersister : public Persister {
    public:
      Image* load(const char *fileName) {
        std::cout << "Loading bmp" << std::endl;
        return new BitmapImage;
      }

      void save(Image *image, const char *fileName) {
        std::cout << "Saving bmp" << std::endl;
      }
  };
}

#endif
