#include <map>

namespace Persistence {
  class Image {
    private:
      unsigned int width, height;
      int* red, green, blue;
  };

  class Persister {
    public:
      virtual Image* load(const char *fileName) = 0;
  };
};
