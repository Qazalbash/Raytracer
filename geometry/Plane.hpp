#ifndef PLANE_HPP
#define PLANE_HPP

/**
   This file declares the Plane class which represents a plane defined by an
   included point and its normal.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"
#include "Geometry.hpp"

class Plane : public Geometry {
    protected:

        Point3D  a;
        Vector3D n;

    public:

        Plane();
        Plane(const Point3D &, const Vector3D &);
        Plane(const Plane &);

        virtual ~Plane() = default;

        Plane &operator=(const Plane &);

        virtual std::string to_string() const override;

        virtual bool hit(const Ray &, float &, ShadeInfo &) const override;

        virtual BBox getBBox() const override;
};

#endif
