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

    Vector3D dir;

public:

    Parallel();
    Parallel(float);
    Parallel(float, float, float);
    Parallel(const Vector3D &);

    Parallel(const Parallel &);
    Parallel &operator=(const Parallel &);

    virtual Vector3D get_direction(const Point3D &) const;
};

#endif