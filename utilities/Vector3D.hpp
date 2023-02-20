/**
   This file declares the class Vector3D which represents a 3D vector.

   Courtesy Kevin Suffern.
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>

class Point3D;

class Vector3D {
    public:

        double x = 0, y = 0, z = 0;

    public:

        Vector3D();
        Vector3D(double);
        Vector3D(double, double, double);
        Vector3D(const Point3D &);
        Vector3D(const Vector3D &) = default;

        ~Vector3D() = default;

        std::string to_string() const;

        Vector3D  operator-() const;
        Vector3D  operator+(const Vector3D &) const;
        Vector3D &operator+=(const Vector3D &);
        Vector3D  operator-(const Vector3D &) const;
        Vector3D &operator-=(const Vector3D &);
        Vector3D &operator=(const Vector3D &) = default;
        Vector3D &operator=(const Point3D &);
        Vector3D  operator*(const double) const;
        Vector3D  operator/(const double) const;
        double    operator*(const Vector3D &) const;
        Vector3D  operator^(const Vector3D &) const;

        void normalize();

        double length() const;
        double len_squared() const;
};

Vector3D operator*(const double, const Vector3D &);

#endif