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

        Image(int, int);
        Image(const ViewPlane &);

        ~Image();

        void set_pixel(int, int, const RGBColor &);
        void set_pixel(int, int, const RGBColor &, int);

        void write_ppm(std::string) const;

    private:

        int        hres, vres;
        RGBColor **colors;
};

#endif