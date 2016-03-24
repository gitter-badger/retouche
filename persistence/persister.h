#ifndef PERSISTER_H
#define PERSISTER_H

namespace Persistence {
  class Image {
    private:
      unsigned int width, height;
      int* red, green, blue;
  };

  class Persister {
    public:
      virtual Image* load(const char *fileName) = 0;
      virtual void save(Image *image, const char *fileName) = 0;
  };
};

#endif
