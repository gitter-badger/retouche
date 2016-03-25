# re-touché

**re-touché** is an image manipulation tool that applies filters (**grayscale**, **gaussian blur**) to images (**bmp**, **jpeg**).

## Commands

**re-touché** is a command-line application driven by commands. Here is the list of supported commands and the available parameters for each of them.

`read` command supports the following parameters:
* `bmp`
* `png`

`write` command supports the following parameters:
* `bmp`
* `png`

`apply` command supports the following parameters:
* `blur` - Applies Gaussian blur filter.
* `grayscale` - Turns the colors of an image into shades of gray.
* `inverse` - Inverses the colors of an image.

```bash
retouche read:bmp from:samples/picture.bmp apply:grayscale write:bmp to:samples/grayscaled.bmp
```
