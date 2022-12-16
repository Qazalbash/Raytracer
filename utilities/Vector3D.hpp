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

    double x = 0, y = 0, z = 0;  // the components.

public:

    // Constructors.
    Vector3D();                        // set vector to (0, 0, 0).
    Vector3D(double);                  // set vector to (c, c, c).
    Vector3D(double, double, double);  // set vector to (_x, _y, _z).
    Vector3D(const Point3D &);         // construct from a point.

    // Copy constructor and assignment operator.
    Vector3D(const Vector3D &)            = default;
    Vector3D &operator=(const Vector3D &) = default;
    // Assign vector from other entitites.
    Vector3D &operator=(const Point3D &);  // from a point.

    // Destructor.
    ~Vector3D() = default;

    // String representation.
    std::string to_string() const;

    // Arithmetic.
    Vector3D  operator-() const;                  // unary minus
    Vector3D  operator+(const Vector3D &) const;  // addition.
    Vector3D &operator+=(const Vector3D &);       // compound addition.
    Vector3D  operator-(const Vector3D &) const;  // subtraction.
    Vector3D &operator-=(const Vector3D &);       // compound subtraction.

    // Scaling.
    Vector3D operator*(const double) const;
    Vector3D operator/(const double) const;
    void     normalize();  // nomalize - convert to a unit vector.

    // Length.
    double length() const;       // length.
    double len_squared() const;  // square of the length.

    // Vector products.
    double   operator*(const Vector3D &) const;  // dot product.
    Vector3D operator^(const Vector3D &) const;  // cross product.
};

// Scaling.
Vector3D operator*(const double, const Vector3D &);

#endif  // VECTOR_HPP