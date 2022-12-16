#ifndef PERSPECTIVE_HPP
#define PERSPECTIVE_HPP

/**
   This file declares the Perspective class which represents a perspective
   viewing camera.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "Camera.hpp"

class Vector3D;

class Perspective : public Camera {
protected:

    Point3D pos;  // center of projection.

public:

    // Constructors.
    Perspective();                     // set pos to origin.
    Perspective(float);                // set pos to (c, c, c).
    Perspective(float, float, float);  // set pos to (x, y, z)
    Perspective(const Point3D &);      // set pos parallel to pt.

    // Copy constuctor and assignment operator.
    Perspective(const Perspective &);
    Perspective &operator=(const Perspective &);

    // Get direction of projection for a point.
    virtual Vector3D get_direction(const Point3D &) const;
};

#endif  // PERSPECTIVE_HPP