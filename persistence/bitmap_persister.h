#include <iostream>

namespace Persistence {
  class BitmapImage : public Image {};

  class BitmapPersister : public Persister {
    Image* load(const char *fileName) {
      std::cout << "Loading bmp" << std::endl;
      return new BitmapImage;
    }
  };
};
