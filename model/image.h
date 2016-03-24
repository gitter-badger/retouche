#ifndef IMAGE_H
#define IMAGE_H

namespace Model {
typedef unsigned char Color;

class Image {
public:
    Image(unsigned int _width, unsigned int _height);

    unsigned int width() const;
    unsigned int height() const;

    Color red(unsigned int x, unsigned int y) const;
    Color green(unsigned int x, unsigned int y) const;
    Color blue(unsigned int x, unsigned int y) const;

    void setRed(unsigned int x, unsigned int y, Color color);
    void setGreen(unsigned int x, unsigned int y, Color color);
    void setBlue(unsigned int x, unsigned int y, Color color);

private:
    unsigned int _width, _height;
    Color *_reds, *_greens, *_blues;
};
}
#endif
