#ifndef SHADEINFO_HPP
#define SHADEINFO_HPP

/**
   This file declares the class ShadeInfo which contains all the relevant
   information for shading a point.

   Courtesy Kevin Suffern.
*/

#include <cstdlib>

#include "Constants.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

class Material;
class World;

class ShadeInfo {
public:

    bool         hit;
    Material    *material_ptr;
    Point3D      hit_point;
    Vector3D     normal;
    Ray          ray;
    int          depth;
    float        t;
    const World *w;

public:

    ShadeInfo(const World &);
    ShadeInfo(const ShadeInfo &) = default;

    ~ShadeInfo() = default;
};

#endif