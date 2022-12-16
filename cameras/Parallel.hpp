#ifndef PARALLEL_HPP
#define PARALLEL_HPP

/**
   This file declares the Parallel class which represents a parallel viewing
   camera.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Vector3D.hpp"
#include "Camera.hpp"

class Parallel : public Camera {
protected:

    Vector3D dir;  // direction of projection, stored as a unit vector.

public:

    // Constructors.
    Parallel();                     // set dir parallel to -z (negative z) axis.
    Parallel(float);                // set dir parallel to (c, c, c).
    Parallel(float, float, float);  // set dir parallel to (x, y, z)
    Parallel(const Vector3D &);     // set dir parallel to d.

    // Copy constuctor and assignment operator.
    Parallel(const Parallel &);
    Parallel &operator=(const Parallel &);

    // Get direction of projection for a point.
    virtual Vector3D get_direction(const Point3D &) const;
};

#endif  // PARALLEL_HPP