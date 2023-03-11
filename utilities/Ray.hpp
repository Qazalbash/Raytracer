#ifndef RAY_HPP
#define RAY_HPP

/**
   This file declares the class Ray which represents a ray.

   Courtesy Kevin Suffern.
*/

#include "Point3D.hpp"
#include "Vector3D.hpp"

class Ray {
public:

    Point3D  o;
    Vector3D d;
    float    w;

public:

    Ray();
    Ray(const Point3D &, const Vector3D &);
    Ray(const Ray &) = default;

    Ray &operator=(const Ray &) = default;

    ~Ray() = default;

    std::string to_string() const;
};

#endif