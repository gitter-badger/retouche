#ifndef IMAGE_H
#define IMAGE_H

#include "../core/sized_array.h"

namespace Model {
typedef unsigned char Color;

class Image {
public:
    Image(unsigned _width, unsigned _height);

    unsigned width() const;
    unsigned height() const;

    Color red(unsigned x, unsigned y) const;
    Color green(unsigned x, unsigned y) const;
    Color blue(unsigned x, unsigned y) const;

    void setRed(unsigned x, unsigned y, Color color);
    void setGreen(unsigned x, unsigned y, Color color);
    void setBlue(unsigned x, unsigned y, Color color);

    void setReds(SizedArray<Color> &colors);
    void setGreens(SizedArray<Color> &colors);
    void setBlues(SizedArray<Color> &colors);

private:
    void checkBounds(unsigned x, unsigned y) const;

    unsigned _width, _height;
    SizedArray<Color> _reds, _greens, _blues;
};
}
#endif
