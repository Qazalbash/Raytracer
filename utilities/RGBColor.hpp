#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP
/**
   This file declares the class RGBColor which represents an RGB color.

   Each of the r, g, b components is clamped within [0,1], i.e. if a component
   becomes less than 0 or greater than 1, e.g. due to an operation, it is made
   equal to 0 or 1 respectively.

  Courtesy Kevin Suffern.
*/

#include <string>

class RGBColor {
    public:

        float r, g, b;

    public:

        RGBColor();
        RGBColor(float);
        RGBColor(float, float, float);

        ~RGBColor() = default;

        RGBColor(const RGBColor &) = default;

        std::string to_string() const;

        RGBColor  operator+(const RGBColor &) const;
        RGBColor &operator+=(const RGBColor &);
        RGBColor  operator*(const float) const;
        RGBColor  operator*(const RGBColor &) const;
        RGBColor &operator*=(const float);
        RGBColor  operator/(const float) const;
        RGBColor &operator/=(const float);
        RGBColor &operator=(const RGBColor &) = default;
        bool      operator==(const RGBColor &) const;

        RGBColor powc(float) const;
        float    average() const;
};

RGBColor operator*(const float, const RGBColor &);

#endif