#ifndef SPHERE_HPP
#define SPHERE_HPP

/**
   This file declares the Sphere class which represents a sphere defined by its
   center and radius.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "Geometry.hpp"

class Sphere : public Geometry {
    protected:

        Point3D c;
        float   r;

    public:

        Sphere();
        Sphere(const Point3D &, float);
        Sphere(const Sphere &);

        virtual ~Sphere() = default;

        Sphere &operator=(const Sphere &);

        std::string to_string() const override;

        virtual bool hit(const Ray &, float &, ShadeInfo &) const override;

        virtual BBox getBBox() const override;
};

#endif