#include <stdexcept>

#include "image.h"

namespace Model {
Image::Image(unsigned width, unsigned height):
    _width(width), _height(height),
    _reds(Array<byte>(width * height)),
    _greens(Array<byte>(width * height)),
    _blues(Array<byte>(width * height)) {}

unsigned Image::width() const {
    return _width;
}

unsigned Image::height() const {
    return _height;
}

byte Image::red(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _reds[x * _height + y];
}

byte Image::green(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _greens[x * _height + y];
}

byte Image::blue(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _blues[x * _height + y];
}

void Image::setRed(unsigned x, unsigned y, byte color) {
    checkBounds(x, y);

    _reds[x * _height + y] = color;
}

void Image::setGreen(unsigned x, unsigned y, byte color) {
    checkBounds(x, y);

    _greens[x * _height + y] = color;
}

void Image::setBlue(unsigned x, unsigned y, byte color) {
    checkBounds(x, y);

    _blues[x * _height + y] = color;
}

void Image::setReds(Array<byte> &colors) {
    checkLength(colors);

    _reds = colors;
}

void Image::setGreens(Array<byte> &colors) {
    checkLength(colors);

    _greens = colors;
}

void Image::setBlues(Array<byte> &colors) {
    checkLength(colors);

    _blues = colors;
}

void Image::checkBounds(unsigned x, unsigned y) const {
    if (x >= _width || y >= _height) {
        throw std::invalid_argument("index out of image bounds");
    }
}

void Image::checkLength(const Array<byte> &colors) const {
    if (colors.size() != _width * _height) {
        throw std::invalid_argument("different color lengths");
    }
}
}
