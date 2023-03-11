#ifndef IMAGE_HPP
#define IMAGE_HPP

/**
   This file declares the Image class which is a utility for storing image
   pixels and writing them to file in PPM format.

   x increases to the right, and y to the bottom.
*/

#include <fstream>
#include <string>

#include "../world/ViewPlane.hpp"
#include "BBox.hpp"
#include "RGBColor.hpp"

class RGBColor;
class ViewPlane;

class Image {
public:

    Image(const size_t, const size_t);
    Image(const ViewPlane &);

    ~Image();

    void set_pixel(const size_t, const size_t, const RGBColor &);
    void set_pixel(const size_t, const size_t, const RGBColor &, const int);

    void write_ppm(const std::string) const;

private:

    size_t     hres, vres;
    RGBColor **colors;
};

#endif