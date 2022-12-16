#ifndef POINT3D_HPP
#define POINT3D_HPP

/**
   This file declares the class Point3D which represents a 3D point.

   Courtesy Kevin Suffern.
*/

#include <string>

#include "Vector3D.hpp"

class Vector3D;

class Point3D {
public:

    float x, y, z;  // the co-ordinates.

public:

    // Constructors.
    Point3D();                     // set point to (0, 0, 0).
    Point3D(float);                // set point to (c, c, c).
    Point3D(float, float, float);  // set point to (x,y,z).

    // Destructor.
    ~Point3D() = default;

    // Copy constructor and assignment operator.
    Point3D(const Point3D &)            = default;
    Point3D &operator=(const Point3D &) = default;

    // String representation.
    std::string to_string() const;

    // Arithmetic.
    Point3D  operator-() const;                  // unary minus.
    Vector3D operator-(const Point3D &) const;   // vector joining two points
    Point3D  operator+(const Vector3D &) const;  // addition of a vector
    Point3D  operator-(const Vector3D &) const;  // subtraction of a vector
    Point3D  operator*(const float) const;  // scale the point by a factor, s.

    // Distance between points.
    float d_squared(const Point3D &) const;  // square of distance
    float distance(const Point3D &) const;   // distance
};

// Scale pt by a factor, s.
Point3D operator*(const float, const Point3D &);

// Compare points.
Point3D min(const Point3D &, const Point3D &);
Point3D max(const Point3D &, const Point3D &);

#endif  // POINT3D_HPP