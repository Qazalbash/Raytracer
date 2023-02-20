#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

/**
   This file declares the Triangle class which represents a triangle defined by
   its 3 vertices.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "Geometry.hpp"

class Triangle : public Geometry {
    protected:

        Point3D v0, v1, v2;

    public:

        Triangle();
        Triangle(const Point3D &, const Point3D &, const Point3D &);
        Triangle(const Triangle &);

        virtual ~Triangle() = default;

        Triangle &operator=(const Triangle &);

        std::string to_string() const override;

        virtual bool hit(const Ray &, float &, ShadeInfo &) const override;

        virtual BBox getBBox() const override;
};

#endif