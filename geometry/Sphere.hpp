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

    Point3D c;  // center.
    float   r;  // radius.

public:

    // Constructors.
    Sphere();                        // sphere at origin with radius 0.
    Sphere(const Point3D &, float);  // set center and radius,

    // Copy constructor and assignment operator.
    Sphere(const Sphere &);
    Sphere &operator=(const Sphere &);

    // Destructor.
    virtual ~Sphere() = default;

    // String representation.
    std::string to_string() const override;

    // Ray intersection. Set t and sinfo as per intersection with this object.
    virtual bool hit(const Ray &, float &, ShadeInfo &) const override;

    // Get bounding box.
    virtual BBox getBBox() const override;
};

#endif  // SPHERE_HPP