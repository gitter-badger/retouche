#include "image.h"

namespace Model {
Image::Image(unsigned int width, unsigned int height):
    _width(width), _height(height) {

    _reds = new Color[width * height];
    _greens = new Color[width * height];
    _blues = new Color[width * height];
}

unsigned int Image::width() const {
    return _width;
}

unsigned int Image::height() const {
    return _height;
}

Color Image::red(unsigned int x, unsigned int y) const {
    return _reds[x * _height + y];
}

void Image::setRed(unsigned int x, unsigned int y, Color color) {
    _reds[x * _height + y] = color;
}

Color Image::green(unsigned int x, unsigned int y) const {
    return _greens[x * _height + y];
}

void Image::setGreen(unsigned int x, unsigned int y, Color color) {
    _greens[x * _height + y] = color;
}

Color Image::blue(unsigned int x, unsigned int y) const {
    return _blues[x * _height + y];
}

void Image::setBlue(unsigned int x, unsigned int y, Color color) {
    _blues[x * _height + y] = color;
}
}
