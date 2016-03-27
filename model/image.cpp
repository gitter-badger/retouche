#include <stdexcept>

#include "image.h"

namespace model {

Image::Image(unsigned width, unsigned height):
    _width(width), _height(height),
    _reds(core::Array<core::byte>(width * height)),
    _greens(core::Array<core::byte>(width * height)),
    _blues(core::Array<core::byte>(width * height)),
    _alphas(core::Array<core::byte>(width * height))	{

    for (unsigned i = 0; i < width * height; i++) {
        _alphas[i] = core::BYTE_MAX;
    }
}

unsigned Image::width() const {
    return _width;
}

unsigned Image::height() const {
    return _height;
}

unsigned Image::pixelsCount() const {
    return _width * _height;
}

core::byte Image::red(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _reds[y * _width + x];
}

core::byte Image::green(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _greens[y * _width + x];
}

core::byte Image::blue(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _blues[y * _width + x];
}

core::byte Image::alpha(unsigned x, unsigned y) const {
    checkBounds(x, y);

    return _alphas[y * _width + x];
}

void Image::setRed(unsigned x, unsigned y, core::byte color) {
    checkBounds(x, y);

    _reds[y * _width + x] = color;
}

void Image::setGreen(unsigned x, unsigned y, core::byte color) {
    checkBounds(x, y);

    _greens[y * _width + x] = color;
}

void Image::setBlue(unsigned x, unsigned y, core::byte color) {
    checkBounds(x, y);

    _blues[y * _width + x] = color;
}

void Image::setAlpha(unsigned x, unsigned y, core::byte alpha) {
    checkBounds(x, y);

    _alphas[y * _width + x] = alpha;
}

void Image::setReds(core::Array<core::byte> &colors) {
    checkLength(colors);

    _reds = colors;
}

void Image::setGreens(core::Array<core::byte> &colors) {
    checkLength(colors);

    _greens = colors;
}

void Image::setBlues(core::Array<core::byte> &colors) {
    checkLength(colors);

    _blues = colors;
}

void Image::setAlphas(core::Array<core::byte> &alphas) {
    checkLength(alphas);

    _alphas = alphas;
}

void Image::checkBounds(unsigned x, unsigned y) const {
    if (x >= _width || y >= _height) {
        throw std::invalid_argument("index out of image bounds");
    }
}

void Image::checkLength(const core::Array<core::byte> &colors) const {
    if (colors.size() != _width * _height) {
        throw std::invalid_argument("different color lengths");
    }
}
}
