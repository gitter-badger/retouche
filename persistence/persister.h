#ifndef PERSISTER_H
#define PERSISTER_H

namespace Persistence {
class Image {
public:
    Image(unsigned int _width, unsigned int _height):
        width(_width), height(_height) {

        red = new unsigned char[width * height];
        green = new unsigned char[width * height];
        blue = new unsigned char[width * height];
    }

    unsigned int getWidth() const {
        return width;
    }

    unsigned int getHeight() const {
        return height;
    }

    unsigned char getRed(unsigned int x, unsigned int y) const {
        return red[x * height + y];
    }

    void setRed(unsigned int x, unsigned int y, unsigned char color) {
        red[x * height + y] = color;
    }

    unsigned char getGreen(unsigned int x, unsigned int y) const {
        return green[x * height + y];
    }

    void setGreen(unsigned int x, unsigned int y, unsigned char color) {
        green[x * height + y] = color;
    }

    unsigned char getBlue(unsigned int x, unsigned int y) const {
        return blue[x * height + y];
    }

    void setBlue(unsigned int x, unsigned int y, unsigned char color) {
        blue[x * height + y] = color;
    }
private:
    unsigned int width, height;
    unsigned char *red, *green, *blue;
};

class Persister {
public:
    virtual Image* load(const char *fileName) = 0;
    virtual void save(Image *image, const char *fileName) = 0;
};
};

#endif
