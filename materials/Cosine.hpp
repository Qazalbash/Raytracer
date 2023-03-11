#ifndef COSINE_HPP
#define COSINE_HPP

/**
   This file declares the Cosine class which represents a simple cosine
   material.

   It assigns a shade according to the cosine of the angle between the incoming
   ray direction and the normal at the hit point.

   Courtesy Kevin Suffern.
*/

#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "Material.hpp"

class Cosine : public Material {
protected:

    RGBColor color;

public:

    Cosine();
    Cosine(float);
    Cosine(float, float, float);
    Cosine(const RGBColor &);

    Cosine(const Cosine &);
    Cosine &operator=(const Cosine &);

    virtual RGBColor shade(const ShadeInfo &) const override;
};

#endif