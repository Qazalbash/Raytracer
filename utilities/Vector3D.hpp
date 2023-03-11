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

    float x = 0, y = 0, z = 0;

public:

    Vector3D();
    Vector3D(float);
    Vector3D(float, float, float);
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
    Vector3D  operator*(const float) const;
    Vector3D  operator/(const float) const;
    float     operator*(const Vector3D &) const;
    Vector3D  operator^(const Vector3D &) const;

    void normalize();

    float length() const;
    float len_squared() const;
};

Vector3D operator*(const float, const Vector3D &);

#endif