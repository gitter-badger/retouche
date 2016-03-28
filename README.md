# re-touché

[![Join the chat at https://gitter.im/s2gatev/retouche](https://badges.gitter.im/s2gatev/retouche.svg)](https://gitter.im/s2gatev/retouche?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

[![MIT License](http://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

**re-touché** is an image manipulation tool that applies filters (**grayscale**, **gaussian blur**) to images (**bmp**, **jpeg**).

```bash
retouche read:bmp from:samples/picture.bmp apply:transformation:flip(horizontal) apply:filter:grayscale write:bmp to:samples/grayscaled.bmp
```

## Commands

**re-touché** is a command-line application driven by command statements.

* The `read:?` command specifies the format of the file being loaded. The `?` should be one of `bmp`, `jpeg`, `png`.
* The `from:?` command specifies the location of the file used to load the image.
* The `write:?` command specifies the format of the file being saved. The `?` should be one of `bmp`, `jpeg`, `png`.
* The `to:?` command specifies the location of the file the image should be saved to.
* The `apply:?` command performs an image manipulation. The `?` should be one of `filter:blur`, `filter:inverse`, `filter:grayscale`, `transformation:flip(?) where ? is either horizontal or vertical`.
