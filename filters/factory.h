#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

namespace Filters {
  Filter* get(const std::string &type) {
    if (type == "grayscale") {
      return new GrayscaleFilter;
    }
    return nullptr;
  }
}

#endif
