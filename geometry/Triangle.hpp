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

    Point3D v0, v1, v2;  // the vertices. they must not be colinear.

public:

    // Constructors. Passed vertices are assumed to be ordered for orientation,
    Triangle();  // triangle with vertices at origin.
    Triangle(const Point3D &, const Point3D &,
             const Point3D &);  // set vertices.

    // Copy constructor and assignment operator.
    Triangle(const Triangle &);
    Triangle &operator=(const Triangle &);

    // Destructor.
    virtual ~Triangle() = default;

    // String representation.
    std::string to_string() const override;
    // Ray intersection. Set t and sinfo as per intersection with this object.
    virtual bool hit(const Ray &, float &, ShadeInfo &) const override;

    // Get bounding box.
    virtual BBox getBBox() const override;
};

#endif  // TRIANGLE_HPP