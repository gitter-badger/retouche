#ifndef IMAGE_H
#define IMAGE_H

#include "../core/array.h"
#include "../core/types.h"

namespace Model {
class Image {
public:
    Image(unsigned _width, unsigned _height);

    unsigned width() const;
    unsigned height() const;

    byte red(unsigned x, unsigned y) const;
    byte green(unsigned x, unsigned y) const;
    byte blue(unsigned x, unsigned y) const;

    void setRed(unsigned x, unsigned y, byte color);
    void setGreen(unsigned x, unsigned y, byte color);
    void setBlue(unsigned x, unsigned y, byte color);

    void setReds(Array<byte> &colors);
    void setGreens(Array<byte> &colors);
    void setBlues(Array<byte> &colors);

private:
    void checkBounds(unsigned x, unsigned y) const;
    void checkLength(const Array<byte> &colors) const;

    unsigned _width, _height;
    Array<byte> _reds, _greens, _blues;
};
}
#endif
