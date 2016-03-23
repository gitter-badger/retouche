#include <iostream>

namespace Persistence {
  class JpegImage : public Image {};

  class JpegPersister : public Persister {
    Image* load(const char *fileName) {
      std::cout << "Loading jpeg" << std::endl;
      return new JpegImage;
    }
  };
};
