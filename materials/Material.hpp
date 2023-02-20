#ifndef MATERIAL_HPP
#define MATERIAL_HPP

/**
   This file declares the Material class which is an abstract class for concrete
   materials to inherit from.

   Courtesy Kevin Suffern.
*/

class RGBColor;
class ShadeInfo;

class Material {
    public:

        Material() = default;

        Material(const Material &)            = default;
        Material &operator=(const Material &) = default;

        virtual ~Material() = default;

        virtual RGBColor shade(const ShadeInfo &) const = 0;
};

#endif