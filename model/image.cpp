#include <stdexcept>

#include "image.h"

namespace Model {
Image::Image(unsigned int width, unsigned int height):
    _width(width), _height(height),
    _reds(SizedArray<Color>(width * height)),
    _greens(SizedArray<Color>(width * height)),
    _blues(SizedArray<Color>(width * height)) {}

unsigned int Image::width() const {
    return _width;
}

unsigned int Image::height() const {
    return _height;
}

Color Image::red(unsigned int x, unsigned int y) const {
    checkBounds(x, y);

    return _reds[x * _height + y];
}

Color Image::green(unsigned int x, unsigned int y) const {
    checkBounds(x, y);

    return _greens[x * _height + y];
}

Color Image::blue(unsigned int x, unsigned int y) const {
    checkBounds(x, y);

    return _blues[x * _height + y];
}

void Image::setRed(unsigned int x, unsigned int y, Color color) {
    checkBounds(x, y);

    _reds[x * _height + y] = color;
}

void Image::setGreen(unsigned int x, unsigned int y, Color color) {
    checkBounds(x, y);

    _greens[x * _height + y] = color;
}

void Image::setBlue(unsigned int x, unsigned int y, Color color) {
    checkBounds(x, y);

    _blues[x * _height + y] = color;
}

void Image::setReds(SizedArray<Color> &colors) {
    if (_reds.size() != colors.size()) {
        throw std::invalid_argument("different color lengths");
    }

    _reds = colors;
}

void Image::setGreens(SizedArray<Color> &colors) {
    if (_greens.size() != colors.size()) {
        throw std::invalid_argument("different color lengths");
    }

    _greens = colors;
}

void Image::setBlues(SizedArray<Color> &colors) {
    if (_blues.size() != colors.size()) {
        throw std::invalid_argument("different color lengths");
    }

    _blues = colors;
}

void Image::checkBounds(unsigned x, unsigned y) const {
    if (x >= _width || y >= _height) {
        throw std::invalid_argument("index out of image bounds");
    }
}
}
