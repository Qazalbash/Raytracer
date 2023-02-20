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

        float x, y, z;

    public:

        Point3D();
        Point3D(float);
        Point3D(float, float, float);
        Point3D(const Point3D &) = default;

        ~Point3D() = default;

        std::string to_string() const;

        Point3D  operator-() const;
        Vector3D operator-(const Point3D &) const;
        Point3D  operator+(const Vector3D &) const;
        Point3D  operator-(const Vector3D &) const;
        Point3D  operator*(const float) const;
        Point3D &operator=(const Point3D &) = default;

        float d_squared(const Point3D &) const;
        float distance(const Point3D &) const;
};

Point3D operator*(const float, const Point3D &);

Point3D min(const Point3D &, const Point3D &);
Point3D max(const Point3D &, const Point3D &);

#endif