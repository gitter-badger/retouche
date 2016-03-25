#ifndef MODEL_IMAGE_H
#define MODEL_IMAGE_H

#include "../core/array.h"
#include "../core/types.h"

namespace Model {

// A model representing an RGB raster image.
class Image {
public:
    // Constructs the image with specific width and height.
    Image(unsigned _width, unsigned _height);


    // Returns the width of the image.
    unsigned width() const;
    // Returns the height of the image.
    unsigned height() const;


    // Returns the red color value at a specific position of the image.
    byte red(unsigned x, unsigned y) const;

    // Returns the green color value at a specific position of the image.
    byte green(unsigned x, unsigned y) const;

    // Returns the blue color value at a specific position of the image.
    byte blue(unsigned x, unsigned y) const;

    byte alpha(unsigned x, unsigned y) const;


    // Sets the red color value at a specific position of the image.
    void setRed(unsigned x, unsigned y, byte color);

    // Sets the green color value at a specific position of the image.
    void setGreen(unsigned x, unsigned y, byte color);

    // Sets the blue color value at a specific position of the image.
    void setBlue(unsigned x, unsigned y, byte color);

    void setAlpha(unsigned x, unsigned y, byte alpha);


    // Sets the red colors for every pixel of the image.
    void setReds(Array<byte> &colors);

    // Sets the green colors for every pixel of the image.
    void setGreens(Array<byte> &colors);

    // Sets the blue colors for every pixel of the image.
    void setBlues(Array<byte> &colors);

    void setAlphas(Array<byte> &alphas);

private:
    // Verifies that x and y specify a pixel contained inside the image bounds.
    void checkBounds(unsigned x, unsigned y) const;

    // Verifies that the length of colors is equal to the number of pixels in the image.
    void checkLength(const Array<byte> &colors) const;

    unsigned _width, _height;
    Array<byte> _reds, _greens, _blues, _alphas;
};
}

#endif
