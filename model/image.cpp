#include <stdexcept>

#include "image.h"

namespace Model {
Image::Image(unsigned width, unsigned height):
    _width(width), _height(height),
    _reds(Array<byte>(width * height)),
    _greens(Array<byte>(width * height)),
    _blues(Array<byte>(width * height)),
    _alphas(Array<byte>(width * height))	{

    for (unsigned i = 0; i < width * height; i++) {
        _alphas[i] = BYTE_MAX;
    }
}

unsigned Image::width() const {
    return _width;
}

unsigned Image::height() const {
    return _height;
}

byte Image::red(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _reds[y * _width + x];
}

byte Image::green(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _greens[y * _width + x];
}

byte Image::blue(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _blues[y * _width + x];
}

byte Image::alpha(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _alphas[y * _width + x];
}

void Image::setRed(unsigned x, unsigned y, byte color) {
    checkBounds(x, y);

    _reds[y * _width + x] = color;
}

void Image::setGreen(unsigned x, unsigned y, byte color) {
    checkBounds(x, y);

    _greens[y * _width + x] = color;
}

void Image::setBlue(unsigned x, unsigned y, byte color) {
    checkBounds(x, y);

    _blues[y * _width + x] = color;
}

void Image::setAlpha(unsigned x, unsigned y, byte alpha) {
    checkBounds(x, y);

    _alphas[y * _width + x] = alpha;
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

void Image::setAlphas(Array<byte> &alphas) {
    checkLength(alphas);

    _alphas = alphas;
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
